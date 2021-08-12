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
typedef tree<ii, null_type, less<ii>, 
rb_tree_tag, tree_order_statistics_node_update> ost;

void solve() {
	int n,l,r;cin>>n>>l>>r;
	ost tree;
	int x;
	cin>>x;
	tree.insert({x,0});
	ll tot =0;
	REPL(i,1, n){
		cin>>x;
		int mn = tree.order_of_key({l-x, -1});
		int mx = tree.order_of_key({r-x+1, -1});
		tot += (mx-mn);
		tree.insert({x,i});
	}
	cout<<tot<<"\n";

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