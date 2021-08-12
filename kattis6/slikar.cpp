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
	int r,c;
	cin>>r>>c;
	vector<string> arr(r);
	vii water;
	vii src;
	ii d;
	REP(i, r) {
		cin>>arr[i];
		REP(j,c) {
			if (arr[i][j]=='D') {
				d = {i,j};
			} 
			if (arr[i][j]=='S') {
				src.push_back({i,j});
				arr[i][j] = '.';
			}
			if (arr[i][j] == '*') {
				water.push_back({i, j});
			}
		}
	}
	vi vdir = {0,0,-1,1};
	vi udir = {1,-1,0,0};
	vvi dist(r, vi(c, INF));
	dist[src.front().first][src.front().second] =0;
	while (true) {
		if (src.empty()) {
			break;
		}
		vii nw;
		for (auto [rr,cc]: water) {
			REP(i, 4) {
				int nr = rr + vdir[i];
				int nc = cc + udir[i];
				if (nr<0||nr>=r||nc<0||nc>=c) continue;
				if (arr[nr][nc] =='.') {
					arr[nr][nc] = '*';
					nw.push_back({nr,nc});
				}
			}
		}
		water = nw;
		vii ns;
		for (auto [rr,cc]: src) {
			if (d.first == rr && d.second == cc) {
				cout<<dist[rr][cc];return 0;
			}
			REP(i, 4) {
				int nr = rr + vdir[i];
				int nc = cc + udir[i];
				if (nr<0||nr>=r||nc<0||nc>=c) continue;
				if (arr[nr][nc] != '*' && arr[nr][nc]!= 'X' && dist[nr][nc]==INF) {
					dist[nr][nc] = dist[rr][cc] +1;
					ns.push_back({nr,nc});
				}
			}
		}
		src = ns;
	}
	cout<<"KAKTUS";
}