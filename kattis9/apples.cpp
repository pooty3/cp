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
	int r,c;
	cin>>r>>c;
	vector<string> arr(r);
	REP(i, r) {
		cin>>arr[i];
	}
	vector<string> farr(r,"");
	REP(i, r) {
		REP(j,c) {
			farr[i] += ".";
		}
	}
	REP(j, c) {
		int curb =r-1;
		REP(i, r) {
			if (arr[r-1-i][j] == 'a') {
				farr[curb][j] = 'a';
				curb--;
			}
			if (arr[r-1-i][j] == '#') {
				farr[r-1-i][j] = '#';
				curb = r-2-i;
			}
		}
	}
	REP(i, r) {
		REP(j, c) {
			cout<<farr[i][j];
		}cout<<"\n";
	}

}