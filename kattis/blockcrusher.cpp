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
		int h,w;
		cin>>h>>w;
		if (h==0) break;
		vvi arr(h, vi(w));
		REP(i, h) {
			string str;
			cin>>str;
			REP(j, w) {
				arr[i][j] = str[j] - '0';
			}
		}
		vvi dist(h+1, vi(w+1, INF));
		vector<vii> btrack(h+1, vii(w+1));
		set<pair<int, ii>> mp;
		REP(i, w) {
			dist[0][i] = 0;
			btrack[0][i] = {-1,-1};
		}
		REP(i, h) {
			REP(j, w) {
				mp.insert({dist[i][j], {i,j}});
			}
		}
		mp.insert({dist[h][w], {h,w}});
		while (!mp.empty()) {
			auto [wei, p] = *mp.begin();
			if (p.second == w) break;
			mp.erase(mp.begin());
			REPL(i, -1, 2) {
				REPL(j, -1, 2) {
					int ni = p.first + i;
					int nj = p.second + j;
					if (ni<0||ni>h||nj<0||nj>=w) continue;
					if (ni==h) {nj = w;}
					if (dist[ni][nj] > wei + arr[p.first][p.second]) {
						mp.erase(mp.find({dist[ni][nj], {ni, nj}}));
						dist[ni][nj] = wei+ arr[p.first][p.second];
						mp.insert({dist[ni][nj], {ni,nj}});
						btrack[ni][nj] = p;
					}
				}
			}
		}

		ii cur = btrack[h][w];
		while (cur.first != -1) {
			arr[cur.first][cur.second] = -1;
			cur = btrack[cur.first][cur.second];
		}
		REP(i, h) {
			REP(j, w) {
				if (arr[i][j]==-1) {
					cout<<" ";
				} else {
					cout<<arr[i][j];
				}		
			}			
			cout<<"\n";
		}cout<<"\n";

	}

}