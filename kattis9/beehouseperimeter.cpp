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
	int r,k;
	cin>>r>>k;
	set<int> s;
	REP(i, k) {
		int x;
		cin>>x;
		s.insert(x);
	}
	int l= r*2-1;
	vvi grid(l, vi(l, 0));
	int cur =1;
	REP(i, r) {
		REP(j, i+r) {
			if (s.find(cur)!=s.end()) {
				grid[i][j] = 1;
			} 
			cur++;
		}
	}
	REP(i, r-1) {
		REP(j, l-1-i) {
			if (s.find(cur)!=s.end()) {
				grid[i+r][j+1+i] = 1;
			} 
			cur++;
		}
	}
	vvi grid2(l+2, vi(l+2,0));
	REP(i, l) {
		REP(j, l) {
			grid2[i+1][j+1] = grid[i][j];
		}
	}
	int co=0;
	queue<ii> q;
	bool vis[l+2][l+2];
	memset(vis, 0, sizeof(vis));
	REP(i, l+2) {
		q.push({i, 0});
		q.push({i, l+1});
		q.push({0, i});
		q.push({l+1, 0});
	}
	while(!q.empty()) {
		auto [r,c] = q.front(); q.pop();
		if (grid2[r][c]==1) {
			co++;
			continue;
		}
		if (vis[r][c]) continue;
			vis[r][c] = true;
		if (grid2[r][c]!=0) continue;
		REP(i, 6) {
			int nr = r + rdir[i];
			int nc = c + cdir[i];
			if (nr<0||nr>=l+2||nc<0||nc>=l+2) continue;
			q.push({nr,nc});
		}
	}cout<<co;

}