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

vi cdir = {0,1,1,0,-1,-1};
vi rdir = {-1,0,1,1,0,-1};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int r,n,a,b,x;
	cin>>r>>n>>a>>b>>x;
	set<int> s;
	REP(i, x) {
		int y;cin>>y;
		s.insert(y);
	}
	int l= r*2-1;
	vvi grid(l, vi(l,0));
	ii st;
	ii ed;
	int cur =1;
	REP(i, r) {
		REP(j, i+r) {
			if (cur == a) {
				st = {i,j};
			}if (cur == b) {
				ed = {i,j};
			}
			if (s.find(cur)==s.end()) {
				grid[i][j] = 1;
			}
			cur++;
		}
	}
	REP(i, r-1) {
		REP(j, l-1-i) {
			if (cur == a) {
				st = {i+r,j+1+i};
			}if (cur == b) {
				ed = {i+r,j+1+i};
			}
			if (s.find(cur)==s.end()) {
				grid[i+r][j+1+i] = 1;
			}
			cur++;
		}
	}
	vvi dist(l, vi(l, INF));
	dist[st.first][st.second] =0;
	queue<ii> q;
	q.push(st);
	while (!q.empty()) {
		auto [r,c] = q.front();q.pop();
		REP(i, 6) {
			int nr = r + rdir[i];
			int nc = c + cdir[i];
			if (nr<0||nr>=l||nc<0||nc>=l||dist[nr][nc]!=INF||grid[nr][nc]==0) continue;
			dist[nr][nc] = dist[r][c] + 1;
			q.push({nr,nc});
		}
	}
	int val = dist[ed.first][ed.second];
	if (val <= n) {
		cout<<val;
	}else {
		cout<<"no";
	}
}