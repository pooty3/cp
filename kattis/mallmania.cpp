#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true) {
		int n;
		cin>>n;
		if (n ==0) break;
		vvi dist(2001, vi(2001, INF));
		queue<ii> q;
		REP(i, n) {
			int x,y;
			cin>>x>>y;
			dist[x][y] = 0;
			q.push({x,y});
		}
		int vdir[] = {0,0,-1,1};
		int udir[] = {1,-1,0,0};
		while (!q.empty()) {
			ii v = q.front();
			q.pop();
			REP(i,4) {
				int x = v.first + vdir[i];
				int y = v.second + udir[i];
				if (x>=0&&x<2001&&y>=0&&y<2001&&dist[x][y]==INF) {
					dist[x][y] = dist[v.first][v.second] +1;
					q.push({x,y});
				}
			}
		}
		int mn = INF;
		cin>>n;
		REP(i, n) {
			int x,y;
			cin>>x>>y;
			mn = min(dist[x][y], mn);
		}
		cout<<mn<<"\n";
	}

}