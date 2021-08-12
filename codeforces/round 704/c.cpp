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
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	vi marr(m);
	vector<set<int>> sarr(26, set<int>());
	REP(i, n) {
		sarr[s[i] - 'a'].insert(i);
	}
	int curmx = n;
	REP(i, m) {
		int index = *prev(sarr[t[m-1-i] - 'a'].lower_bound(curmx));
		curmx = index;
		marr[m-1-i] = index;
	}
	vi farr(m);
	farr[0] = *sarr[t[0] - 'a'].begin();
	int curmn = farr[0];
	int curwd = 0;
	REPL(i, 1, m) {
		curwd = max(curwd, marr[i] - farr[i-1]);
		farr[i] = *sarr[t[i] - 'a'].upper_bound(curmn);
		curmn = farr[i];
	}
	cout<<curwd;

}