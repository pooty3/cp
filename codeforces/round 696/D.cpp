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
int n;



void solve() {
	cin>>n;
	vi arr(n);
	vi tarr;
	REP(i, n) {
		cin>>arr[i];
	}
	vi mx(n),mn(n);
	mx[0] = arr[0];
	mn[1] = arr[0]-arr[1];
	int curval =arr[0]-arr[1];
	REPL(i, 2, n) {
		curval += arr[i] * (i%2==0? 1: -1);
		if (i%2==0) {
			mx[i] = min(mx[i-2], curval);
		} else {
			mn[i] = max(mn[i-2], curval);
		}
	}
	bool par = n%2==0;
	if (curval== 0 && mx[par?n-2:n-1] >=0 && mn[par?n-1:n-2]<=0) {
		cout<<"YES\n";
		return;
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