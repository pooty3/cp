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
typedef tuple<int,int,int> iii;
vi xdir = {0,0,0,0,-1,1};
vi ydir = {0,0,-1,1,0,0};
vi zdir = {1,-1,0,0,0,0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true){
	int l,r,c;
	cin>>l>>r>>c;
	if (l==0 &&r==0&&c==0) break;
	vector<vector<string>>arr(l, vector<string>(r));
	iii st,ed;
	REP(i, l) {
		REP(j, r) {
			cin>>arr[i][j];
			REP(k, c){
				if (arr[i][j][k]=='S') {
					st = {i,j,k};
				} 
				if (arr[i][j][k]=='E') {
					ed = {i,j,k};
				}
			}
		}
	}
	vector<vvi> dist(l, vvi(r, vi(c,-1)));
	auto [x,y,z] = st;
	dist[x][y][z] = 0;
	queue<iii> q;
	q.push(st);
	while (!q.empty()) {
		auto [x,y,z]= q.front();q.pop();
		REP(i, 8) {
			int nx = x+ xdir[i];
			int ny = y + ydir[i];
			int nz = z + zdir[i];
			if (nx<0||nx>=l||ny<0||ny>=r||nz<0||nz>=c) continue;
			if (dist[nx][ny][nz]==-1 && arr[nx][ny][nz]!='#') {
				dist[nx][ny][nz] = 1+dist[x][y][z];
				q.push({nx,ny,nz});
			}
		}
	}
	auto [ex,ey,ez] = ed;
	int val = dist[ex][ey][ez];
	if (val == -1) {
		cout<<"Trapped!\n";
	} else {
		cout<<"Escaped in "<<val<<" minute(s).\n";
	}
}}