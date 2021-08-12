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
	int n,m;
	cin>>n>>m;
	map<int, vi> mp;
	REP(i, m) {
		int r,c;
		cin>>r>>c;
		if (mp.find(c)==mp.end()) {
			mp.insert({c, vi()});
		}
		mp[c].push_back(r);
	}
	int state=0;
	int pos = 0;
	bool able = true;
	for (auto &[p, arr] : mp) {
		if (state==0) {
			pos = p;
			if (arr.size()==1) {
				if (arr[0]==1) {
					state = 2;
				} else {
					state =1;
				}
			}
		} else if (state==1||state==2) {
			if (arr.size()==2) {
				able = false; break;
			} else {
				bool off = (p-pos)%2==1;
				if ((off&&state==arr[0])||(!off&&state!=arr[0])) {
					able = false;
					break;
				}
				state=0;
				pos = p;			
			}
		}
	}
	if (state==0&&able) {
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