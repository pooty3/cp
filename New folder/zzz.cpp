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

vvi removeIslands(vvi &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	bool vis[n][m];
	memset(vis, 0,sizeof(vis));
	queue<ii> q;
	REP(i, n) {
		if(matrix[i][0]==1) {
			q.push({i,0});
		}
		if (matrix[i][n-1] == 1) {
			q.push({i, n-1});
		}
	}
	REP(i, m) {
		if(matrix[0][i]==1) {
			q.push({0,i});
		}
		if (matrix[n-1][i] == 1) {
			q.push({n-1, i});
		}
	}
	set<ii> marked;
	vi vdir = {0,0,-1,1};
	vi udir = {1,-1,0,0};
	while (!q.empty()) {
		auto [r,c] = q.front(); q.pop();
		if (vis[r][c]) continue;
		marked.insert({r,c});
		vis[r][c]= true;
		REP(i,4) {
			int nr = r + vdir[i];
			int nc = c + udir[i];
			if (nr < 0 ||nr >= n || nc<0||nc>=m||matrix[nr][nc]==0||vis[nr][nc]) continue;
			q.push({nr,nc});
		}
	}
	vvi farr(n, vi(m));
	REP(i, n) {
		REP(j,m) {
			if (marked.find({i,j})== marked.end() || matrix[i][j] == 0) {
				farr[i][j] = 0;
			} else {
				farr[i][j] = 1;
			}
		}
	}

	return farr;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vvi arr(n, vi(m));
	REP(i, n) {
		REP(j, m) {
			cin>>arr[i][j];
		}
	}
	vvi farr = removeIslands(arr);
	REP(i, n) {
		REP(j, m) {
			cout<<farr[i][j]<<" ";
		}cout<<"\n";
	}
}