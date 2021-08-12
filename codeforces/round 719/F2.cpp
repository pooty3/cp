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

void solve(int l, int r, int k) {
	int len = r-l+1;
	if (len == k) {
		cout<<"! "<<r<<endl; return;
	}
	int md = (l+r)/2;
	cout<<"? "<<l<<" "<<md<<endl;
	int x;
	cin>>x;
	int zo = md-l+1-x;
	if (k>zo) {
		solve(md+1, r, k-zo);
	} else {
		solve(l,md, k);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,t;cin>>n>>t;
	int k;
	cin>>k;
	vi parr;
	parr.push_back(0);
	int bucketSize =16;
	int cur =0;
	for (int i = 1; i <= n; i+=bucketSize) {
		cout<<"? "<<i<<" "<<min(n,(i+bucketSize-1))<<endl;
		int x;cin>>x;
		cur += (bucketSize -x);
		parr.push_back(cur);
	}
	REP(i, t) {
		int ind = lower_bound(parr.begin(), parr.end(), k) - parr.begin()-1;
		solve(ind*bucketSize +1, min(n, (ind+1)*bucketSize), k-parr[ind]);
		REPL(j, ind+1, parr.size()) {
			parr[j]--;
		}
		if (i!=t-1) {
			cin>>k;
		}
	}
}