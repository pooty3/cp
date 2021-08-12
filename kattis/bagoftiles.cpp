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

ll combiarr[31][31];



void solve(int g) {
	int m;
	scanf("%d", &m);
	vvll larr(31, vll(10001, 0LL)), rarr(31, vll(10001, 0LL));
	vll varr(m);
	REP(i, m) {
		scanf("%d", &(varr[i]));
	}
	int mid = m/2;
	REP(i, 1<<mid) {
		int co=0;
		int tot=0;
		REP(j, mid) {
			if (i&(1<<j)) {
				co++;
				tot+= varr[j];
			}
		}
		if (tot<10001) {
			larr[co][tot]++;
		}
	}
	REP(i, 1<<(m-mid)) {
		int co=0;
		int tot=0;
		REP(j, m-mid) {
			if (i&(1<<j)) {
				co++;
				tot+= varr[mid+j];
			}
		}
		if (tot<10001) {
			rarr[co][tot]++;
		}
	}
	int n,t;
	scanf("%d %d", &n, &t);
	ll tot = combiarr[m][n];
	ll winable =0;
	REP(i, n+1) {
		REP(j, t+1) {
			winable += larr[i][j]*rarr[n-i][t-j];
		}
	}
	printf("Game %d -- %lld : %lld\n", g+1, winable, tot-winable);

}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	REP(i, 31) {
		REP(j, i+1) {
			if (i==j||j==0) {
				combiarr[i][j] =1;
			} else {
				combiarr[i][j] = combiarr[i-1][j-1] + combiarr[i-1][j];
			}
		}
	}
	int tc;
	scanf("%d", &tc);
	REP(i, tc) {
		solve(i);
	}

}