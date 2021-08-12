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
bool visited[100][100];

void DFS(vector<string> &str, int x, int y) {
	if (x>=0&&x<str.size()&&y>=0&&y<str[0].length()&&str[x][y]=='#'&&!visited[x][y]) {
		visited[x][y]= true;
		REP(i, 3) {
			REP(j,3) {
				DFS(str, x-1+i, y-1+j);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int m, n;
	cin>>m>>n;
	vector<string> arr(m);
	REP(i, m) {
		cin>>arr[i];
	}
	memset(visited, 0, sizeof(visited));
	int tot =0;
	REP(i,m){
		REP(j,n) {
			if (arr[i][j]=='#'&&!visited[i][j]) {
				tot++;
				DFS(arr,i,j);
			}
		}
	}
	cout<<tot;
}