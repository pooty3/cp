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
int css=0;
void solve() {
	css++;
	printf("Case %d\n", css);
	int n,m,l;
	scanf("\n%d %d %d",&n,&m,&l);
	set<pair<ll, string>> ss;
	REP(i, l) {
		string name;
		int A,B;
		while (true) {
			char ch;
			scanf("\n%c", &ch);
			if (ch == ':') break;
			name += ch;
		}
		scanf("%d,%d",&A,&B);
		ll cur =0;
		int curn = n;
		while (curn!=m) {
			int halfed = curn/2;
			if (halfed < m) {
				cur += (ll)A*(curn-m);
				curn = m;
			} else {
				cur += min((ll)A*(curn-halfed), (ll)B);
				curn = halfed;
			}
		}
		ss.insert({cur, name});
	}
	for (auto [cs, ch]: ss) {
		printf("%s %lld\n", ch.c_str(), cs);
	}

}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	scanf("%d", &tc);
	REP(i, tc) {
		solve();
	}

}