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
	int n,k;
	cin>>n>>k;
	map<int, int> mp;
	mp.insert({1, n});
	int diff = n-k;
	int v =1;
	int amt = n;
	while (true) {
		cout<<diff<<endl;
		if (amt< 2*diff) {
			mp[v] -= (amt/2) * 2;
			diff -= amt/2;
			mp.insert({2*v, amt/2});
			v *= 2;
			amt /= 2;
		} else {
			mp[v] -= diff * 2;
			mp.insert({2*v, diff});
			diff =0;
			break;
		}
	}
	FOREACH(it, mp) {
		int amt = it->second;
		int v = it->first;
		REP(i, amt) {
			cout<<v<<" ";
		}
	}
	cout<<"\n";

}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}