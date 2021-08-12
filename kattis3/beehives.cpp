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

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	while (true) {
		ld d; int n;
		cin>>d>>n;
		if (n==0) break;
		vector<pair<ld,ld>> arr(n);
		REP(i, n) {
			ld x,y;cin>>x>>y;
			arr[i] = {x,y};

		}
		int swe =0;
		REP(i,n) {
			bool sweet =1;
			REP(j, n) {
				if (i==j) continue;
				ld dy = arr[i].first - arr[j].first;
				ld dx = arr[i].second - arr[j].second;
				if (dy*dy + dx*dx <= d*d) {
					sweet =0;break;
				}
			}
			swe += sweet;
		}
		printf("%d sour, %d sweet\n", n-swe, swe);
	}

}