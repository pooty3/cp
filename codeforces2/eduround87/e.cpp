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
int curcomp = 0;
bool isable(int amt, int cur, vvi &dp, vvi &arr) {
	if (cur==curcomp) {
		if (amt ==0) return true;
		else {
			return false;
		}
	}
	if (amt < 0) return false;
	if (dp[cur][amt]== -1) {
		bool able = false;
		REP(i, 2) {
			if (isable(amt-arr[cur][i], cur+1, dp, arr)) {
				able = true;
			}
		}
		dp[cur][amt] = able ? 1:0;
	}return dp[cur][amt]==1;
}
void solve() {
	int n,m;cin>>n>>m;
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	vvi adj(n, vi());
	REP(i, m){
		int u,v;cin>>u>>v;u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vi col(n, -1);
	vi comp(n, -1);
	REP(i, n) {
		if (comp[i]!=-1) continue;
		queue<int> q;
		q.push(i);
		col[i] = 0;
		comp[i] = curcomp;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto v:adj[u]) {
				if (col[v]==col[u]) {
					cout<<"NO\n"; return;
				}if (col[v]==-1) {
					col[v] = 1-col[u];
					comp[v] = comp[u];
					q.push(v);
				}
			}
		}
		curcomp++;
	}
	vvi colors(curcomp, vi(2,0));
	REP(i, n) {
		colors[comp[i]][col[i]]++;
	}
	vvi dp(curcomp, vi(n+1, -1));
	if (!isable(n2, 0, dp, colors)) {
		cout<<"NO\n"; return;
	} 
	cout<<"YES\n";
	vi allocation(curcomp, -1);
	int curamt = n2;
	REP(i, curcomp) {
		REP(j, 2) {
			if (isable(curamt - colors[i][j], i+1, dp, colors)) {
				allocation[i] = j;
				curamt -= colors[i][j];
				break;
			}
		}
	}
	REP(i, n) {
		if (allocation[comp[i]]==col[i]) {
			cout<<2;
		} else {
			if (n1>0) {
				cout<<1;n1--;
			} else {
				cout<<3;
			}
		}
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc=1;
	REP(i, tc) {
		solve();
	}

}