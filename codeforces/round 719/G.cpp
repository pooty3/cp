#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999999999999999
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

vi udir = {0,0,-1,1};
vi vdir = {1,-1,0,0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	ll w;
	cin>>n>>m>>w;
	vvll arr(n, vll(m));
	REP(i, n) {
		REP(j, m) {
			cin>>arr[i][j];
		}
	}

	vvll distH(n, vll(m, INF));
	queue<ii> q;
	distH[0][0] =0;
	q.push({0,0});
	while (!q.empty()) {
		auto [r,c] = q.front(); q.pop();
		REP(i, 4) {
			int nr = r + udir[i];
			int nc = c + vdir[i];
			if (nr<0||nr>=n||nc<0||nc>=m||arr[nr][nc]==-1||distH[nr][nc]!=INF) continue;
			distH[nr][nc] = w + distH[r][c];
			q.push({nr,nc});
		}
	}
	vvll distS(n, vll(m,INF));
	distS[n-1][m-1] =0;
	q.push({n-1,m-1});
	while (!q.empty()) {
		auto [r,c] = q.front(); q.pop();
		REP(i, 4) {
			int nr = r + udir[i];
			int nc = c + vdir[i];
			if (nr<0||nr>=n||nc<0||nc>=m||arr[nr][nc]==-1||distS[nr][nc]!=INF) continue;
			distS[nr][nc] = w + distS[r][c];
			q.push({nr,nc});
		}
	}
	ll curb = distH[n-1][m-1];
	ll bestH  = INF;
	ll bestS = INF;
	REP(i, n) {
		REP(j, m) {
			if (arr[i][j]<=0) continue;
			bestH = min(bestH, distH[i][j] + arr[i][j]);
			bestS = min(bestS, distS[i][j] + arr[i][j]);
		}
	}
	curb = min(curb, bestH+bestS);
	if (curb == INF) {
		cout<<-1;
	} else {
		cout<<curb;
	}
}