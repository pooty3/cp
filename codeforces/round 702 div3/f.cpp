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
	int n;
	cin>>n;
	map<int,int> mp;
	REP(i, n) {
		int x;
		cin>>x;
		if (mp.find(x)==mp.end()) {
			mp.insert({x,0});
		}
		mp[x]++;
	}
	vi arr;
	FOREACH(it,mp) {
		arr.push_back(it->second);
	}
	n = arr.size();
	SORT(arr);
	vi pfsum(n);
	int tot =0;
	REP(i, n) {
		tot += arr[i];
		pfsum[i] = tot;
	}	
	int curmn =INF;
	REP(i, n) {
		int tcut = i==0? 0: pfsum[i-1];
		int excess = pfsum[n-1] - pfsum[i];
		int tot = tcut + excess - arr[i] * (n-1-i);
		curmn = min(tot, curmn);
	}
	cout<<curmn<<"\n";
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