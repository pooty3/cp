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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	ii s;
	vector<string> arr(n);
	REP(i, n) {
		cin>>arr[i];
		REP(j, n) {
			if (arr[i][j]=='K') {
				s = {i,j};
			}
		}
	}
	vvi dist(n, vi(n, -1));
	dist[s.first][s.second] = 0;
	queue<ii> q;
	q.push(s);
	while (!q.empty()) {
		auto [r,c] = q.front();
		q.pop();
		REPL(i,-2,3) {
			REPL(j,-2, 3) {
				if (abs(i)+abs(j)!=3) continue;
				int nr = r+i;
				int nc = c+j;
				if (nr<0||nr>=n||nc<0||nc>=n||dist[nr][nc]!=-1||arr[nr][nc]=='#') {
					continue;
				}
				dist[nr][nc] = dist[r][c] +1;
				q.push({nr,nc});
			}
		}
	}cout<<dist[0][0];
}