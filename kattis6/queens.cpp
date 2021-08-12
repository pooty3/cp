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
void wrong() {
	cout<<"INCORRECT";
	exit(0);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;
	bool arr[n][n];
	vii dirs = {{0,1}, {1,0}, {1,1}, {-1,1}};
	memset(arr, 0, sizeof(arr));
	REP(i, n) {
		int x,y;cin>>x>>y;
		if (arr[x][y]) {
			wrong();
		}
		arr[x][y] =1;
		for (auto [xx,yy] : dirs) {
			int curx = x;
			int cury = y;
			while (true) {
				curx += xx;
				cury+= yy;
				if (curx<0||curx>=n||cury<0||cury>=n) {
					break;
				}
				arr[curx][cury] = 1;
			}
			curx = x;
			cury = y;
			while (true) {
				curx -= xx;
				cury-= yy;
				if (curx<0||curx>=n||cury<0||cury>=n) {
					break;
				}
				arr[curx][cury] = 1;
			}
		}
	}cout<<"CORRECT";

}