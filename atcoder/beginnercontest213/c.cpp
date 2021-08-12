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
	int h,w,n;
	cin>>h>>w>>n;
	map<int, vi> harr;
	map<int, vi> varr;
	REP(i,n) {
		int a,b;
		cin>>a>>b;
		if (harr.find(a)==harr.end()) {
			harr.insert({a, vi()});
		}
		if (varr.find(b)==varr.end()) {
			varr.insert({b, vi()});
		}
		harr[a].push_back(i);
		varr[b].push_back(i);
	}
	vi hans(n);
	vi vans(n);
	int curind = 1;
	FOREACH(it, harr) {
		for (auto j: it->second) {
			hans[j] = curind;
		}
		curind++;
	}
	curind=1;
	FOREACH(it, varr) {

		for (auto j: it->second) {
			vans[j] = curind;
		} curind++;
	}
	REP(i, n) {
		cout<<hans[i]<<" "<<vans[i]<<"\n";
	}

}