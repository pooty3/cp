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
	int n,k;
	cin>>n>>k;
	vll arr(n);
	vll psum(n);
	ll cur = 0;
	REP(i, n) {
		ll x;
		cin>>x;
		arr[i] = x;
		psum[i] = cur;
		cur+= x;
	}
	ll incre = 0;
	REP(i, n) {
		if (i==n-1) {
			break;
		}
		ll cur100 = 100* arr[n-1-i];
		if (cur100 > k * (psum[n-1-i] + incre)) {
			ll def = cur100 - k * (psum[n-1-i] + incre);
			incre += def/k;
			if (def%k!=0) {
				incre++;
			}
		}
	}
	cout<<incre<<"\n";
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