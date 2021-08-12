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

void solve() {
	string str;
	cin>>str;
	int n = str.length();
	if (n==1) {
		cout<<0<<"\n";
	} else {
	vi CC(n), CS(n), SS(n), SC(n);
	CC[1] = 2;
	CS[1] = SC[1] = 1;
	SS[1] = str[0]==str[1]?INF:0;
	REPL(i, 2, n) {
		CC[i]= min(SC[i-1], CC[i-1]) +1;
		SC[i] = min(SS[i-1], CS[i-1]) +1;
		if (str[i]!=str[i-2]) {
			CS[i] = min(CC[i-1], SC[i-1]);
		} else {
			CS[i] = CC[i-1];
		}
		if (str[i]==str[i-1]) {
			SS[i] = INF;
		} else if (str[i]==str[i-2]) {
			SS[i] = CS[i-1];
		} else {
			SS[i] = min(CS[i-1], SS[i-1]);
		}

	}
	cout<<min(min(CS[n-1], SS[n-1]), min(SC[n-1], CC[n-1]))<<"\n";
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}