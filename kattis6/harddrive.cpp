#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define REPR(i,m, n) for(int i = m; i > n; i --)
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,c,b;cin>>n>>c>>b;
	vi arr(n,-1);
	REP(i, b) {
		int x;
		cin>>x;
		arr[x-1] =0;
	}
	REPR(i, n-2, 0) {
		if (arr[i]==-1) {
			if (c<=1) {
				arr[i] =0;
			} else {
				arr[i] = 1- arr[i+1];
			}
		}
		c -= arr[i]!= arr[i+1];
	}
	if (c == 1) {
		arr[0] = 1- arr[1];
	} else {
		arr[0] = arr[1];
	}
	for (auto i:arr) {
		cout<<i;
	}

}