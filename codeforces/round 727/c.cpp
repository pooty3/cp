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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll n,k,x;
	cin>>n>>k>>x;
	vl arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	SORT(arr);
	vll darr;
	REP(i, n-1) {
		ll diff = arr[i+1]-arr[i];
		ll nd = diff/x -1;
		if (diff%x!=0) nd++;
		if (nd > 0) {
			darr.push_back(nd);
		}
	}
	int grps = darr.size()+1;
	SORT(darr);

	for (auto j:darr) {
		if (k<j) break;
		k-=j;
		grps--;
	}
	cout<<grps;
}
