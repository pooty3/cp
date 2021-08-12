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
typedef tuple<int, int, int> iii;
typedef double ld;
int h,w;
bool inbound(int hi,int wi) {
	return hi>=0&&hi<h&&wi<w&&wi>=0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>h>>w;
	vector<string> arr(h);
	REP(i, h) {
		cin>>arr[i];
	}
	map<ii, vector<iii>> adj;
	vi udir = {0,0,-1,1};
	vi vdir = {-1,1,0,0};
	REP(i, h) {
		REP(j, w) {
			adj.insert({{i,j}, vector<iii>()});
			REP(z, 4) {
				int ni = i + udir[z];
				int nj = j+vdir[z];
				if (inbound(ni,nj)&&arr[ni][nj]=='.') {
					adj[{i,j}].push_back({ni,nj, 0});
				}
			}
			REPL(ni, i-2, i+3) {
				REPL(nj, j-1, j+3) {
					if (abs(ni-i)==2 && abs(nj-j)==2) continue;
					if (inbound(ni,nj) && arr[ni][nj]=='#') {
						adj[{i,j}].push_back({ni,nj, 1});
					}
				}
			}
		}
	}
	vvi dist(h, vi(w, INF));
	dist[0][0] = 0;
	set<iii> pq;
	REP(i, h) {
		REP(j, w) {
			pq.insert({dist[i][j], i,j});
		}
	}
	while (!pq.empty()) {
		auto [curd, curh, curw] = *pq.begin();pq.erase(pq.begin());
		for (auto [nh, nw,dd]: adj[{curh, curw}]) {
			if (curd + dd< dist[nh][nw]) {
				pq.erase(pq.find({dist[nh][nw], nh, nw}));
				dist[nh][nw] = curd + dd;
				pq.insert({dist[nh][nw], nh, nw});
			}
		}
	} 
	cout<<dist[h-1][w-1];
}