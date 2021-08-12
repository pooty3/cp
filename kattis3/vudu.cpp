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
typedef pair<ll, ll> llll;
typedef tree<llll, null_type, greater<llll>, rb_tree_tag,
             tree_order_statistics_node_update> ost;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;
	vll arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	ll p;
	cin>>p;
	REP(i, n) {
		arr[i]-=p;
	}
	ll cur=0;
	ost tree;
	REP(i,n) {
		cur += arr[i];
		tree.insert({cur, i});
	}
	cur = 0;
	ll tot =0;
	REP(i, n) {
		tot += tree.order_of_key({cur, -1});
		cur += arr[i];
		tree.erase({cur, i});
	}
	cout<<tot;

}