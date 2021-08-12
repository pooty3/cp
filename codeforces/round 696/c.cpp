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
	multiset<int> s;
	REP(i, 2*n) {
		int x;
		cin>>x;
		s.insert(x);
	}
	bool found = false;
	vi arr;
	FOREACH(it, s) {
		if (next(it)== s.end()) break;
		multiset<int> cur = s;
		cur.erase(cur.find(*it));
		int v = *cur.rbegin();
		cur.erase(cur.find(v));
		arr.clear();
		arr.push_back(v);
		arr.push_back(*it);
		while (!cur.empty()) {
			int nv = *cur.rbegin();
			cur.erase(cur.find(nv));
			int diff = v-nv;
			if (cur.find(diff) == cur.end()) {
				break;
			}
			v = nv;
			cur.erase(cur.find(diff));
			arr.push_back(nv);
			arr.push_back(diff);
		}
		if (cur.empty()) {
			found = true;
			break;
		}
	}
	if (!found) {
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
		cout<<(arr[0] + arr[1])<<"\n";
		REP(i, arr.size()/2) {
			cout<<arr[2*i]<<" "<<arr[2*i+1]<<"\n";
		}
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