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
vii tops;
vii bots;

ll findmax(int topmin, int topmax, int botmin, int botmax) {
	if (topmin>topmax) return -INF;
	if (botmin>botmax) return -INF;
	int md = (topmin+topmax)/2;
	ll curmx = -INF;
	ll curind = -1;
	REPL(i, botmin, botmax+1) {
		ll are = ((ll)bots[i].first - (ll)tops[md].first)*((ll)tops[md].second - (ll)bots[i].second);
		if (are > curmx) {
			curind = i;
			curmx = are;
		}
	}
	ll m1 = findmax(topmin, md-1, botmin, curind);
	ll m2 = findmax(md+1, topmax, curind, botmax);
	return max(max(m1, m2), curmx);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	int curmn = 0;
	int curmx = 0;
	REP(i, n) {
		if (arr[i]>curmn) {
			tops.push_back({i, arr[i]});
			curmn = arr[i];
		}
		if (arr[n-i-1]>curmx) {
			bots.push_back({n-i-1, -arr[n-1-i]});
			curmx = arr[n-1-i];
		}
	}
	reverse(bots.begin(), bots.end());
	cout<<findmax(0, tops.size()-1, 0, bots.size()-1);
}