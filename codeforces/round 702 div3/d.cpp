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
class node{
public:
	int v;
	node* lc = nullptr;
	node* rc = nullptr;
};

node* build(vi &arr, int l, int r) {
	if (l==r) {
		return nullptr;
	} else {
		node* n = new node();
		int curind = -1;
		int curmax = 0;
		REPL(i, l, r) {
			if (arr[i]>curmax) {
				curind = i;
				curmax = arr[i];
			}
		}
		n->v = curmax;
		n-> lc= build(arr, l, curind);
		n-> rc= build(arr, curind+1, r);
		return n;
	}
}
void filldepth(vi &arr, node *n, int cur) {
	if (n == nullptr) {
		return;
	} else {
		arr[(n->v)-1] = cur;
		filldepth(arr, n->lc, cur+1);
		filldepth(arr, n->rc, cur+1);
	}
}

void solve() {
	int n;
	cin>>n;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	vi carr(n);
	node* nde = build(arr, 0, n);
	filldepth(carr, nde, 0);
	int mxlvl=-1;
	REP(i, n) {
		cout<<carr[arr[i]-1]<<" ";
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