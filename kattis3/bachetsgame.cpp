#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999999
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

const int N = 1000001;
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n;
	while (cin>>n) {
		int m;
		cin>>m;
		vi arr(m);
		bitset<N> bs;
		REP(i, m) {
			cin>>arr[i];
		}
		SORT(arr);
		REPL(i, 1, n+1) {
			bool cur =0;
 			for (auto v: arr) {
 				if (v> i) break;
 				if (!bs[i-v]) {
 					cur =1;
 				}
 			} 
 			bs[i] = cur;
		}
		if (bs[n]) {
			cout<<"Stan wins\n";
		} else {
			cout<<"Ollie wins\n";
		}
	}

}