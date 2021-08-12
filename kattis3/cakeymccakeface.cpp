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
	int n,m;
	cin>>n>>m;
	set<int> s;
	REP(i, n) {
		int x;
		cin>>x;s.insert(x);
	}
	map<int, int> mp;
	int curb =0;
	int curv =0;
	REP(i, m) {
		int y;
		cin>>y;
		for (auto v:s) {
			if (y<v) break;
			mp[y-v]++;
			if (mp[y-v]>curb) {
				curb = mp[y-v];
				curv = y-v;
			} 
			if (mp[y-v] == curb) {
				curv = min(curv, y-v);
			}
		}
	}
	cout<<curv;


}