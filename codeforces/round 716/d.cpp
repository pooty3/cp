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
	int n,q;cin>>n>>q;
	vi arr(n);
	unordered_map<int, int> tot;
	REP(i, n) {
		cin>>arr[i];
		tot[arr[i]]++;
	}
 
	set<ii> totarr;
	unordered_map<int, vi> pmp;
	for (auto &[z, c] : tot) {
		if ((ll)c*(ll)c < (ll)n) continue;
		totarr.insert({c,z});
		vi parr(n);
		int curp = 0;
		REP(i, n) {
			if (arr[i] == z) {
				++curp;
			}
			parr[i] = curp;
		}
		pmp.insert({z, parr});
	}
	REP(i, q) {
		int l,r;
		cin>>l>>r;l--;r--;
		int amt = (r-l)+1;
		if ((ll)amt * (ll)amt <= 4*(ll)n) {
			int curmax = 0;
			unordered_map<int,int> mp;
			REPL(i,l, r+1) {
				mp[arr[i]]++;
				curmax = max(curmax, mp[arr[i]]);
			}
			cout<<max(1, 2*curmax - amt)<<"\n";
		} else {
			int curmx = 1;
			for (auto it = totarr.rbegin(); it!= totarr.rend(); ++it) {
				auto [c, z] = *it;
				if (c * 2 < amt) {
					break;
				}
				c = pmp[z][r] - (l==0?0:pmp[z][l-1]);
				if (c*2 > amt) {
					curmx = c;
					break;
				}
			}
			cout<<max(1, 2*curmx - amt)<<"\n";
		}
	}
}