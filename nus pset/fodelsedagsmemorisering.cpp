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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	map<string, pair<int, string>> mp;
	REP(i, n) {
		string n, dy;
		int v;
		cin>>n>>v>>dy;
		if (mp.find(dy)== mp.end()) {
			mp.insert({dy, {v, n}});
		} else {
			pair<int, string> p ={v, n};
			mp[dy] = mp[dy].first > v ? mp[dy] :p;
		}
	}
	vector<string> arr;
	FOREACH(it, mp) {
		arr.push_back(it->second.second);
	}
	sort(arr.begin(), arr.end());
	cout<<arr.size()<<"\n";
	FOREACH(it, arr) {
		cout<<(*it)<<"\n";
	}


}