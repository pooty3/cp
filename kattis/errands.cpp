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

int getmask(vi &v) {
	int tot=0;
	REP(i, v.size()) {
		tot += (1<<(v[i]-1));
	}
	return tot;

}

pair<ld, vi> getshort(vector<vector<pair<ld, vi>>> &dp, vector<vector<ld>> &distarr, int mask, int s) {
	if (dp[s][mask].first <0) {
		if (mask ==0) {
			dp[s][mask] = {distarr[s][distarr.size()-1], {}};
		} else {
			int m = mask;
			vi cur ={};
			double mn = INF;
			while (m) {
				int l = LSOne(m);
				int index = __builtin_ctz(l) + 1;
				pair<ld, vi> p = getshort(dp, distarr, mask^l, index);
				if (p.first + distarr[index][s] < mn) {
					mn = p.first + distarr[index][s];
					cur = p.second;
					cur.push_back(index);
				}
				m -=l;
			}
			dp[s][mask] = {mn, cur};
		}
	}
	return dp[s][mask];
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n;
	unordered_map<string, pair<ld,ld>> mp;
	cin>>n;
	string str;
	REP(i, n) {
		ld x,y;
		cin>>str>>x>>y;
		mp.insert({str, {x,y}});
	}
	getline(cin, str);
	while (getline(cin,str)){
		if (str=="") {
			break;
		}
		stringstream s(str);
		vector<string> curarr;
		curarr.push_back("home");
		while(s>>str) {
			curarr.push_back(str);
		}
		curarr.push_back("work");
		vector<vector<ld>> distarr(curarr.size(), vector<ld>(curarr.size(),0));
		REP(i, curarr.size()) {
			REP(j, curarr.size()) {
				distarr[i][j] = sqrt(pow(abs(mp[curarr[i]].first - mp[curarr[j]].first), 2) + 
					pow(abs(mp[curarr[i]].second - mp[curarr[j]].second), 2));
			}
		}
		vector<vector<pair<ld, vi>>> dp(curarr.size()-1, vector<pair<ld,vi>>(1<<(curarr.size()-2), {-1, {0}}));
		vi ar = getshort(dp, distarr, (1<<(curarr.size()-2))-1, 0).second;
		REP(i, ar.size()) {
			cout<<curarr[ar[i]]<<" ";
		}
		cout<<"\n";
	}
}