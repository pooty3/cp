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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int m,n;
	cin>>m>>n;
	vvi arr (m+1, vi(n+1));
	vector<vii> bt (m+1, vii(n+1));
	REP(i, m) {
		REP(j, n) {
			cin>>arr[i][j];
		}
	}
	arr[m][n]=0;
	int vdir[4] = {-1,1,0,0};
	int udir[4] = {0,0,-1,1};
	bool vist[m+1][n+1];
	priority_queue<tuple<int, ii, ii>> pq;
	memset(vist, 0, sizeof (vist));
	REP(i, m) {
		pq.push({0, {-1,-1}, {i,0}});
	}
	while (!pq.empty()) {
		auto [w, s, d] = pq.top(); pq.pop();
		if (!vist[d.first][d.second]) {
			vist[d.first][d.second] = true;
			bt[d.first][d.second] = s;
			REP(i, 4) {
				int ni = d.first+udir[i];
				int nj = d.second + vdir[i];
				if (ni>=0&&ni<m&&nj>=0&&nj<n&&!vist[ni][nj]) {
					pq.push({-arr[d.first][d.second], d, {ni,nj}});
				}
				if (nj==n&&!vist[m][n]) {
					pq.push({-arr[d.first][d.second], d, {m, n}});
				}
			}
		}
	}
	ii curr = {m,n};
	ii des = {-1,-1};
	int curmax =0;
	while (curr!= des) {
		ii ne = bt[curr.first][curr.second];
		curmax = max(curmax, arr[curr.first][curr.second]);
		curr = ne;

	}
	cout<<curmax;


}