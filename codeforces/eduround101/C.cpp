#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
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

void solve() {
	int n;
	ll k;
	cin>>n>>k;
	vll h(n);
	REP(i, n) {
		cin>>h[i];
	}
	ll hmin = h[0];
	ll hmax = h[0];
	bool able = true;
	REPL(i,1, n) {
		if (i!=n-1) {
			if (h[i]>hmax+(k-1)||h[i]<hmin-2*(k-1)) {
			able = false;
			break;
			}
		} else {
			if (h[i]>hmax+(k-1)||h[i]<hmin-(k-1)) {
			able = false;
			break;
			}
		}
		hmax = min(hmax+(k-1), h[i]+(k-1));
		hmin= max(hmin-(k-1), h[i]);
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