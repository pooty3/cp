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

int findmax(vvi &dp , vector<vii> &pr, int w, int n) {
	if (n<0||w>=pr.size()) {
		return 0;
	} else {
		if (dp[w][n]==-1) {
			int mx =-1;
			for (auto &[p, s] : pr[w]) {
				mx = max(mx, findmax(dp, pr, w+1, n-s) + min(n, s)* p);
			}
			dp[w][n] = mx;
		} return dp[w][n];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,w;
	cin>>n>>w;
	vector<vii> p(w+1);
	REP(i, w+1) {
		int k;
		cin>>k;
		vii v(k, {0,0});
		p[i] = v;
		REP(j, k) {
			int pk;
			cin>>pk;
			p[i][j].first = pk;
		} 
		REP(j,k) {
			int sk;
			cin>>sk;
			p[i][j].second = sk;
		}
	}
	vvi dp(w+1, vi(n+1, -1));
	int mx = -1;
	int curp = INF;
	for (auto &[pr, s] : p[0]) {
		int val = findmax(dp, p, 1, n-s) + min(n, s)* pr;
		if (val>mx ||(val==mx&&curp>pr)){
			mx = val;
			curp = pr;
		}
	}
	cout<<mx<<"\n"<<curp;

}