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
	int n;
	cin>>n;
	vi arr;
	set<int> s;
	REP(i, n) {
		int x;
		cin>>x;
		arr.push_back(x);
		s.insert(x);
	}
	int i = 1;
	while (true) {
		if (i>=arr.size()) break;
		REP(j, i) {
			int v = abs(arr[i]-arr[j]);
			if (s.find(v)== s.end()) {
				arr.push_back(v);
				s.insert(v);
				if (s.size() > 301) goto out;
			}
		}
		++i;
	}
	out:
	if (s.size()>301) {
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
		cout<<s.size()<<"\n";
		for (int v: s) {
			cout<<v<<" ";
		}
		cout<<"\n";
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}