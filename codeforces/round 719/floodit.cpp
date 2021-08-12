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
int n;
vvi arr;
vi udir = {0,0,-1,1};
vi vdir = {1,-1,0,0};
int bfs(int num, vii &sarr, bool coloring){
	queue<ii> q;
	bool vis[n][n];
	memset(vis, 0, sizeof(vis));
	for (auto [r,c] : sarr) {
		q.push({r,c});
		vis[r][c] = 1;
	}
	int co = 0;
	while (!q.empty()) {
		co += 1;
		auto [r, c] = q.front();q.pop();
		REP(i, 4) {
			int nr = r + udir[i];
			int nc = c + vdir[i];
			if (nr>=0&&nr<n&&nc>=0&&nc<n && (!vis[nr][nc]) && arr[nr][nc] == num) {
				vis[nr][nc] =1;
				q.push({nr,nc});
				if (coloring) sarr.push_back({nr,nc});
			}
		}
	}
	return co;
}
void solve() {
	cin>>n;
	arr.assign(n, vi(n));
	REP(i, n) {
		string s;cin>>s;
		REP(j, n) {
			arr[i][j] = s[j]-'0';
		}
	}
	vi marr(6,0);
	int tot =0;
	vii sarr = {{0,0}};
	bfs(arr[0][0], sarr, true);
	while (sarr.size() != n*n){
		tot++;
		ii curmx = {0, 0};
		REPL(i, 1,7) {
			curmx = max(curmx, {bfs(i, sarr, false),-i});
		}
		bfs(-curmx.second, sarr, true);
		marr[-curmx.second-1] +=1;
	}
	cout<<tot<<"\n";
	for (auto i: marr) {
		cout<<i<<" ";
	}cout<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}