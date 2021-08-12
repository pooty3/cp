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

void DFS(vvi &arr, vvi &comp, vi &sarr, int xl, int yl, int x, int y, int val, int cellval) {
	if (x>=0&&x<xl&&y>=0&&y<yl&&arr[x][y]==cellval&&comp[x][y]==-1) {
		comp[x][y] = val;
		sarr[val]++;
		DFS(arr, comp, sarr, xl, yl, x-1, y, val, cellval);
		DFS(arr, comp, sarr, xl, yl, x+1, y, val, cellval);
		DFS(arr, comp, sarr, xl, yl, x, y-1, val, cellval);
		DFS(arr, comp, sarr, xl, yl, x, y+1, val, cellval);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int x,y;
	cin>>y>>x;
	vvi arr(x, vi(y));
	vvi comp(x, vi(y,-1));
	vi sarr;
	REP(i, x) {
		REP(j, y) {
			cin>>arr[i][j];
		}
	}
	int cur =0;
	REP(i, x) {
		REP(j, y) {
			if (comp[i][j]==-1) {
				sarr.push_back(0);
				DFS(arr, comp, sarr, x, y,i,j, cur, arr[i][j]);
				cur++;
			}
		}
	}
	vvi adj(cur, vi());
	auto check = [&](int i, int j, int def, int val) {
		if (i<0||i>=x||j<0||j>=y) {
		} else {
			if (arr[i][j] < val) {
				adj[def].push_back(comp[i][j]);
			}
		}
	};
	REP(i, x) {
		REP(j,y) {
			int ind = comp[i][j];
			check(i+1, j, ind, arr[i][j]);
			check(i-1, j, ind, arr[i][j]);
			check(i, j+1, ind, arr[i][j]);
			check(i, j-1, ind, arr[i][j]);
		}
	}
	int tot=0;
	REP(i, cur) {
		if (adj[i].size()==0) {
			tot += sarr[i];
		}
	}
	cout<<tot;

}