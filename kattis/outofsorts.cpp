#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999
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

vll arr;

bool search(int low, int high, ll val) {
	if (low > high) {
		return false;
	} else {
		int ind = (high + low)/2;
		int q= arr[ind];
		if (q== val) {
			return true;
		} else if (q < val){
			return search(ind+1, high, val);
		} else {
			return search(low, ind-1, val);
		}

	}
}

int main()
{
	ll n,m,a,c,x;
	cin>>n>>m>>a>>c>>x;
	ll cur = x;
	REP(i, n) {
		cur = (a*cur + c)%m;
		arr.push_back(cur);
	}
	int tot =0;
	REP(i, n) {
		tot += search(0, n-1, arr[i]);

	}
	cout<<tot;

}