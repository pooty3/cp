#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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
	int n,m;
	cin>>n>>m;
	vvi arr;
	REP(i, n) {
		REP(j,n) {
			int x;
			cin>>x;
			arr.push_back({i,j,x-1});
		}
	}
	vi offsets(3,0);
	int row=0;
	int col =1;
	int val =2;
	string str;
	cin>>str;
	REP(i, m) {
		if (str[i]=='R') {
			offsets[col]++;
		}
		if (str[i]=='L') {
			offsets[col]--;
		}
		if (offsets[col]<0) {
			offsets[col]+=n;
		}
		if (str[i]=='U') {
			offsets[row]--;
		}
		if (str[i]=='D') {
			offsets[row]++;
		}
		if (offsets[row]<0) {
			offsets[row]+=n;
		}

		if (str[i]=='I') {
			int temp = col;
			col = val;
			val = temp;
		}
		if (str[i]=='C') {
			int temp = row;
			row = val;
			val = tem;
		}
	}
	int arr2[n][n];
	REP(i, n*n) {
		int r = (arr[i][row]+ offsets[row])%n;
		int c = (arr[i][col]+offsets[col])%n;
		int v = (arr[i][val]+offsets[val])%n;
		arr2[r][c] =v;
	}
	REP(i,n) {
		REP(j,n) {
			cout<<(arr2[i][j]+1)<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";

}

int main()
{
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}