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
	vi arr(n);
	vi rem;
	queue<int> bad;
	set<int> s;
	REP(i, n) {
		s.insert(i);
		cin>>arr[i];
	}
	REP(i, n) {
		if (s.find(i)==s.end()) continue;
		if (__gcd(arr[i], arr[(i+1)%n])==1) {
			rem.push_back((i+1)%n);
			s.erase(s.find((i+1)%n));
			bad.push(i);
		}
	}
	while (!bad.empty()) {
		int u = bad.front();bad.pop();
		if (s.find(u) == s.end()) continue;
		auto it = s.upper_bound(u);
		int nexnum = it==s.end() ? (*s.begin()) : (*it);
		if (__gcd(arr[u], arr[nexnum])==1) {
			rem.push_back(nexnum);
			s.erase(nexnum);
			bad.push(u);
		}
	}
	cout<<rem.size()<<" ";
	for (int i : rem) {
		cout<<(i+1)<<" ";
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