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
int md = 998244353;
void solve() {
	int n;
	cin>>n;
	vi arr(n);
	ll tot =0;
	REP(i, n) {
		cin>>arr[i];
		tot += arr[i];
	}
	int wys =0;
	ll cur =0;
	REP(i, n) {
		if (cur+arr[n-1-i] <= tot - cur-arr[n-1-i]) {
			break;
		}cur += arr[n-1-i];
		wys++;
	}
	vll paltA;
	vll paltB;
	ll A = 0;
	ll B =0;
	REP(i, n) {
		if (i%2==0) {
			A+=arr[i];
			paltA.push_back(A);
		} else {
			B+= arr[i];
			paltB.push_back(B);
		}
	}
	cur =0;
	REP(i, n) {
		bool isA = i%2==0;
		if (isA) {
			if (cur >= tot-cur) continue;
			int mn = i/2-1;
			int mx = (n-1)/2 * 2;
			while (mn < mx) {
				int md = (mn+mx+1)/2;
				ll val = cur + paltA[md];
			}
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