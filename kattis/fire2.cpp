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

void solve() {
	int w,h;
	cin>>w>>h;
	vector<string> arr(h);
	REP(i, h) {
		cin>>arr[i];
	}
	vvi farr(h, vi(w, INF));
	queue<ii> q;
	ii st;
	REP(i, h) {
		REP(j, w) {
			if (arr[i][j]=='*') {
				farr[i][j] =0;
				q.push({i, j});
			}
			if (arr[i][j]=='@') {
				st = {i,j};
			}
		}
	}
	int udir[] = {0,0,-1,1};
	int vdir[] =  {1, -1, 0, 0};
	while (!q.empty()) {
		ii p = q.front();
		q.pop();
		REP(i, 4) {
			int r = p.first + udir[i];
			int c = p.second + vdir[i];
			if (r>=0&&r<h&&c>=0&&c<w&&arr[r][c]!='#'&&farr[r][c] == INF) {
				farr[r][c] = farr[p.first][p.second] + 1;
				q.push({r,c});
			}
		}
	}
	vvi parr(h, vi(w, INF));
	parr[st.first][st.second] = 0;
	q.push(st);
	bool found = false;
	while (!found&&!q.empty()) {
		ii p = q.front();
		q.pop();
		REP(i, 4) {
			int r = p.first + udir[i];
			int c = p.second + vdir[i];
			if (r<0||r>=h||c<0||c>=w) {
				cout<<(parr[p.first][p.second]+1)<<"\n";
				found = true;
				break;
			} else {
				if (parr[r][c] == INF && farr[r][c] > parr[p.first][p.second]+1&&arr[r][c]!='#') {
					parr[r][c] = parr[p.first][p.second]+1;
					q.push({r,c});
				}
			}
		}
	}
	if (!found) {
		cout<<"IMPOSSIBLE\n";
	}



}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}