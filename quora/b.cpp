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

vi mover= {0,0,-1,1};
vi movec = {-1,1,0,0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	bool block[n][m];
	memset(block, 0, sizeof(block));
	vector<string> arr(n);
	ii s,e;
	REP(i, n) {
		cin>>arr[i];
		REP(j, m){
		if (arr[i][j] == '#') {
			block[i][j] = true;
		}
		if (arr[i][j] == 'S') {
			s = {i,j};
		} 
		if (arr[i][j] == 'E') {
			e = {i,j};
		}
		}
	}
	vector<vii> garr (n*m+1, vii());
	REP(i, k) {
		int r,c,d;
		cin>>r>>c>>d;
		r--;c--;
		garr[d].push_back({r,c});
	}
	queue<ii> cur;
	REP(i, n*m+1) {
		queue<ii> next;
		while (!cur.empty()) {
			auto &[r,c] = cur.front();
			cur.pop();
			REP(zz, 4) {
				if (!block[r+ mover[zz]][c + movec[zz]]) {
					block[r+ mover[zz]][c + movec[zz]] = true;
					next.push({r+ mover[zz], c + movec[zz]});
				}
			}
		}
		for (auto &[r,c] : garr[n*m-i]) {
			if (!block[r][c]) {
				block[r][c] = true;
				next.push({r,c});
			}
		}
		cur = next;
	}
	if (block[s.first][s.second]|| block[e.first][e.second]) {
		cout<<"IMPOSSIBLE";
	} else {
		vvi dist(n, vi(m, INF));
		queue<ii> q;
		q.push(s);
		dist[s.first][s.second] = 0;
		while (!q.empty()) {
			auto [r,c] = q.front();
			q.pop();
			REP(i, 4) {
				int nr = r + mover[i];
				int nc = c + movec[i];
				if (dist[nr][nc]== INF && !block[nr][nc]) {
					dist[nr][nc] = dist[r][c] + 1;
					q.push({nr,nc});
				}
			}
		}
		if (dist[e.first][e.second]== INF) {
			cout<<"IMPOSSIBLE";
		} else {
			cout<<dist[e.first][e.second];
		}
	}

}