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

void solve() {
	int n,k;
	cin>>n>>k;
	set<int> s;
	set<int> mexes;
	REP(i, n+1) {
		mexes.insert(i);
	}

	REP(i, n) {
		int x;
		cin>>x;
		if (mexes.find(x)!=mexes.end()) {
			mexes.erase(mexes.find(x));
		}
		s.insert(x);
	}
	int mex = *mexes.begin();
	if (k==0) {
		cout<<s.size();
	} else {
		if (mex > *s.rbegin()) {
			cout<<(s.size() + k);
		} else {
			int nw = *s.rbegin() + mex;
			s.insert((nw+1)/2);
			cout<<(s.size());
		}
	}
	cout<<"\n";

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