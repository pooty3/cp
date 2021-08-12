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
	int n,m,t;
	cin>>n>>m>>t;
	vector<string> arr(n);
	REP(i,n) {
		cin>>arr[i];
	}
	vvi dist(n, vi(m, INF));
	queue<ii> q;
	vi vdir = {0,0,-1,1};
	vi udir = {-1,1,0,0};
	REP(i, n) {
		REP(j,m) {
			bool found = false;
			REP(z, 4) {
				int ni = i+vdir[z];
				int nj = j+udir[z];
				if (ni>=0&&ni<n&&nj>=0&&nj<m&&arr[ni][nj]==arr[i][j]) {
					found = true;break;
				}
			}
			if (found) {
				dist[i][j] = 0;
				q.push({i,j});
			}
		}
	}
	while(!q.empty()) {
		auto [r,c] = q.front();q.pop();
		REP(i, 4) {
			int nr = r+vdir[i];
			int nc = c+udir[i];
			if (nr>=0&&nr<n&&nc>=0&&nc<m&&dist[nr][nc]==INF) {
				dist[nr][nc] = dist[r][c]+1;
				q.push({nr,nc});
			}
		}
	}
	REP(q, t) {
		int i,j;
		ll p;
		cin>>i>>j>>p;
		i--;j--;
		if (dist[i][j]==INF) {
			cout<<arr[i][j]<<"\n";
		} else {
			ll changes = p-dist[i][j];
			if (changes<=0 || changes%2==0) {
				cout<<arr[i][j]<<"\n";
			} else {
				cout<<(arr[i][j]=='1'?'0':'1')<<"\n";
			}
		}
	}
}