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

bool visited[51][51];
int gold =0;
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

void DFS(vector<string> &arr, int i, int j) {
	if (arr[i][j]!='#'&&!visited[i][j]) {
		visited[i][j] = true;
		if (arr[i][j]=='G') {
			gold++;
		}
		bool movable = true;
		REP(z, 4) {
			if (arr[i+dr[z]][j+dc[z]]=='T') {
				movable = false;break;
			}
		}
		if (movable) {
			REP(z,4) {
				DFS(arr, i+dr[z], j + dc[z]);
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int w,h;
	cin>>w>>h;
	int x,y;
	vector<string> arr(h);
	REP(i, h) {
		cin>>arr[i];
		REP(j, w) {
			if (arr[i][j]=='P') {
				x = j;
				y = i;
			}
		}
	}
	DFS(arr, y, x);
	cout<<gold;

}