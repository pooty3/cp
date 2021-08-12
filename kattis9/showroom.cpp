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
vi udir = {0,0,-1,1};
vi vdir = {1,-1,0,0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int r,c;cin>>r>>c;
	vector<string> arr(r);
	REP(i, r) {
		cin>>arr[i];
	}
	int sr,sc;
	cin>>sr>>sc;sr--;sc--;
	vvi dist(r, vi(c, INF));
	dist[sr][sc] = 1;
	deque<ii> dq;
	dq.push_front({sr,sc});
	while(!dq.empty()) {
		auto [ur,uc] = dq.front(); dq.pop_front();
		REP(i, 4) {
			int nr = ur + udir[i];
			int nc = uc + vdir[i];
			if (nr<0||nr>=r||nc<0||nc>=c||dist[nr][nc]!=INF)continue;
			if (arr[nr][nc]=='#') continue;
			if (arr[nr][nc]=='D') {
				dist[nr][nc] = dist[ur][uc];
				dq.push_front({nr,nc});
			} else {
				dist[nr][nc] = dist[ur][uc]+1;
				dq.push_back({nr,nc});
			}
		}
	}
	int curmn = INF;
	REP(i, r) {
		curmn= min(curmn, dist[i][0]);
		curmn= min(curmn, dist[i][c-1]);
	}
	REP(i, c) {
		curmn= min(curmn, dist[0][i]);
		curmn= min(curmn, dist[r-1][i]);
	}
	cout<<curmn;
}