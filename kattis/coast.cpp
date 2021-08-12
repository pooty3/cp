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

bool v[1005][1005];

int dr[4] = {0,0,-1,1};
int dc[4] = {-1,1,0,0};
int getamount(vvi &arr, int i , int j) {
	if (i<0||i>=arr.size()||j<0||j>=arr[0].size()||v[i][j]) {
		return 0;
	}
	if (arr[i][j] == 1) {
		return 1;
	}
	v[i][j] = true;
	int tot =0;
	REP(z, 4) {
		tot += getamount(arr, i+dr[z], j+ dc[z]);
	}
	return tot;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vvi arr(n+2, vi(m+2,0));
	REP(i,n) {
		string str;
		cin>>str;
		REP(j,m) {
			arr[i+1][j+1] = str[j] - '0';
		}
	}
	memset(v, 0 , sizeof(v));
	cout<<getamount(arr, 0,0);
}