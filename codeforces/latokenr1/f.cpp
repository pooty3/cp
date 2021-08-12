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
bool vis[999999];
void addedge(int u,int v, vvi &adj, vvi &radj) {
	adj[u].push_back(v);
	radj[v].push_back(u);
}
void dfs1(stack<int> &s, vvi &adj, int u) {
	if (vis[u]) return;
	vis[u] = true;
	for (auto v: adj[u]) {
		dfs1(s,adj, v);
	}
	s.push(u);
}
void dfs2(vvi &radj, int u, vi &sccmap, int idx) {
	if (vis[u]) return;
	vis[u] = true;
	sccmap[u] = idx;
	for (auto v: radj[u]) {
		dfs2(radj,v,sccmap, idx);
	}
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n,m;cin>>n>>m;
	vector<string> arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	REP(i,m) {
		int x;cin>>x;
	}
	map<ii, int> mpping;
	vii rmp;
	int no=0;
	REP(i, n) {
		REP(j,m) {
			if (arr[i][j]=='#') {
				mpping.insert({{i,j}, no});
				rmp.push_back({i,j});
				no++;
			}
		}
	}
	vi rdir = {-1,0,0};
	vi cdir = {0,-1,1};
	vi cdir2 = {-1,1};
	vvi adj(no, vi());
	vvi radj(no, vi());
	REP(i, no) {
		auto [r,c] = rmp[i];
		REP(j, 3) {
			int nr = r + rdir[j];
			int nc = c + cdir[j];
			if (nr>=0&&nr<n&&nc>=0&&nc<m&&arr[nr][nc]=='#') {
				addedge(i, mpping[{nr,nc}], adj, radj);
			}
		}
		int curr = r+1;
		while (curr<n) {
			if (arr[curr][c] == '#') {
				addedge(i, mpping[{curr, c}], adj, radj);break;
			}
			REP(j, 2) {

				int nc2 = c + cdir2[j];
				if (nc2>=0&&nc2<m&&arr[curr][nc2]=='#') {
					addedge(i, mpping[{curr, nc2}], adj, radj);
				}
			}
			curr++;
		}
	}
	memset(vis, 0, sizeof(vis));
	stack<int> st;
	REP(i, no) {
		dfs1(st,adj,i);
	}
	vi sccmp(no,-1);
	memset(vis,0,sizeof(vis));
	int curind =0;
	while (!st.empty()) {
		int u = st.top();st.pop();
		if (!vis[u]) {
			dfs2(radj, u, sccmp, curind);curind++;
		}
	}
	vi inedge(curind,0);
	REP(i, no) {
		for (auto j: adj[i]) {
			int u = sccmp[i];
			int v = sccmp[j];
			if (u==v) continue;
			inedge[v]++;
		}
	}
	int co =0;
	for (auto i: inedge) {
		if (i==0) co++;
	}cout<<co;

}