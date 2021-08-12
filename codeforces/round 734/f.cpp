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
ll md = 1e9+7;
void solve() {
	int n,k;cin>>n>>k;
	vvi adj(n, vi());
	REP(i, n-1) {
		int u,v;cin>>u>>v;
		u--;v--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	if (k==2){
		cout<<n*(n-1)/2<<"\n";return;
	}
	ll ways =0;
	REP(tt, n) {
		map<int, vi> mp;
		for (auto st: adj[tt]) {
			vi dist(n, INF);
			dist[st] = 0;
			queue<int> q;
			q.push(st);
			while (!q.empty()){
				int u = q.front();q.pop();
				for (auto v : adj[u]) {
					if (v!=tt&& dist[v]== INF) {
						dist[v] = dist[u]+1;
						q.push(v);
					}
				}
			}
			map<int, int> mp2;

			REP(i, n) {
				if (dist[i]==INF) continue;
				mp2[dist[i]]++;
			}
			for (auto [dd, c]: mp2) {
				if (c==0) continue;
				if (mp.find(dd)== mp.end()) {
					mp.insert({dd, vi()});
				}
				mp[dd].push_back(c);
			}
		}
		for (auto [xx, vv]: mp) {
			if (vv.size()<k) continue;
			vvll dp(vv.size()+1, vll(vv.size()+1,0));
			dp[0][0] = 1;
			REPL(i, 1, vv.size()+1) {
				dp[i][0] =1;
				REPL(j, 1, i+1) {
					dp[i][j] = (dp[i-1][j] + (dp[i-1][j-1]*vv[i-1])%md)%md;
				}
			}
			ways += dp[vv.size()][k];
			ways%=md;
			//cout<<xx<<"::"<<ways<<endl;
		}
		//cout<<tt<<":"<<ways<<endl;
	}cout<<ways<<"\n";

}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}