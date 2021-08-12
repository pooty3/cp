#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vi arr(n);
	REP(i, n) {
		cin>>arr[n-i-1];
	}
	vi darr(n,0);
	vi iarr(n,0);
	int m=0;
	REP(i, n) {
		int md=0;
		int mi=0;
		REP(j, i) {
			if (arr[i] > arr[j]) {
				mi = max(mi, iarr[j]);
			} else {
				md= max(md, darr[j]);
			}
		}
		darr[i] = md +1;
		iarr[i] = mi+1;
		m = max(darr[i]+iarr[i]-1, m);
	}
	cout<<m;


}