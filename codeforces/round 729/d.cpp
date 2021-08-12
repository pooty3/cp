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
ll md = 998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vi arr(n);
	REP(i, n) {
		char c;cin>>c;
		if (c=='-') {
			arr[i] = -1;
		} else {
			int x;cin>>x;
			arr[i] = x;
		}
	}
	ll curtot =0;
	REP(i, n) {
		if (arr[i] == -1) continue;
		vll ways(501, 0);
		ways[0] = 1;
		REP(j, i) {
			vll nways(501);
			if (arr[j] > arr[i]) {
				REP(k, 501) {
					nways[k] = 2*ways[k];
					nways[k] %= md; 
				}
			} else if (arr[j] == -1) {
				nways[0] = 2* ways[0] + ways[1];
				nways[0] %= md;
				REPL(k, 1, 500) {
					nways[k] = ways[k] + ways[k+1];
					nways[k] %= md;
				} 
				nways[500] = ways[500];
			} else {
				nways[0] = ways[0];
				REPL(k, 1, 501) {
					nways[k] = ways[k] + ways[k-1];
					nways[k] %= md;
				}
			}
			ways = nways;
		}
		REPL(j, i+1, n) {
			vll nways(501);
			if (arr[j]>=arr[i]) {
				REP(k, 501) {
					nways[k] = 2*ways[k];
					nways[k] %= md; 
				} 
			} else if (arr[j] == -1) {
				REP(k, 500) {
					nways[k]= ways[k]+ways[k+1];
					nways[k]%=md;
				}
				nways[500] = ways[500];
			} else {
				nways[0] = ways[0];
				REPL(k, 1, 501) {
					nways[k] = ways[k] + ways[k-1];
					nways[k] %= md;
				}
			}
			ways = nways;
		}
		ll totways = 0;
		for (ll val: ways) {
			totways += val;
			totways %=md;
		}
		curtot += (totways*arr[i])%md;
		curtot %=md;

	}
	cout<<curtot;
}