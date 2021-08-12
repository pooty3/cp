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

vector<vector<pair<ll, bool>>> arr;
vi w;
vi v;
ll findmax(int i, int wei) {
	if (wei<0||i<0) {
		return 0;
	}
	if (arr[i][wei].first==-1) {
		if (w[i]> wei) {
			arr[i][wei] = {findmax(i-1, wei), false};
		} else {
			ll hv = findmax(i-1, wei-w[i]) + v[i];
			ll nhv = findmax(i-1, wei);
			if (hv > nhv) {
				arr[i][wei] = {hv, true};
			} else {
				arr[i][wei] = {nhv, false};
			}
		}
	}
	return arr[i][wei].first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int c,n;
	while(cin>>c>>n) {
		arr.assign(n, vector<pair<ll,bool>>(c+1, {-1, false}));
		w.assign(n,0);
		v.assign(n,0);
		REP(i,n) {
			cin>>v[i];
			cin>>w[i];

		}
		ll maxval = findmax(n-1, c);
		int curw;
		REP(i, c+1) {
			if (maxval == arr[n-1][i].first) {
				curw = i;
			}
		}
		vi items;
		REP(i,n) {
			if (arr[n-1-i][curw].second) {
				items.push_back(n-1-i);
				curw -= w[n-1-i];
			}
		}
		cout<<items.size()<<"\n";
		REP(i, items.size()) {
			cout<<items[i]<<" ";
		}
		cout<<"\n";	
	}

}