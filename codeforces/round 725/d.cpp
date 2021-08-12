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
typedef tree<int, null_type, less<int>, 
rb_tree_tag, tree_order_statistics_node_update> ost;
typedef vector<int> vi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

void solve() {
	int n;cin>>n;
	int l =0;
	set<int> s;
	ost tree;
	int x;cin>>x;
	tree.insert(x);
	s.insert(x);
	bool able = true;
	REPL(i,1, n) {
		cin>>x;
		int excess;
		if (s.find(x)==s.end()) {
			excess = 1;
			tree.insert(x);
			s.insert(x);
		} else {
			excess = 2;
		}
		int ind = tree.order_of_key(x);
		int lft = ind + l;
		int def = i - lft;
		if (def < 0|| def>excess) {
			able = false;
		} 
		l += def;
	}
	if (able){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
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