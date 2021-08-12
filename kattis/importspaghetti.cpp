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
	vvi adj(n, vi());
	map<string, int> mp;
	vector<string> sarr(n);
	vvi dp(n, vi(n, INF));
	vvi nex(n, vi(n, -1));
	REP(i, n) {
		string str;
		cin>>str;
		mp.insert({str,i});
		sarr[i] = str;
	}
	REP(i, n) {
		string str;
		int no;
		cin>>str>>no;
		int u = mp[str];
		getline(cin, str);
		REP(j, no) {
			getline(cin, str);
			stringstream s(str);
			s>>str;
			while (s>>str) {
				if (str[str.length()-1]==',') {
					str = str.substr(0, str.length()-1);
				}
			
			adj[u].push_back(mp[str]);
			dp[u][mp[str]]=1;	
			nex[u][mp[str]] = mp[str];
			}
		}
	}
	REP(i, n) {
		REP(j, n) {
			REP(k, n) {
				if (dp[j][k] > dp[j][i] + dp[i][k]){
					dp[j][k] = dp[j][i] + dp[i][k];
					nex[j][k] = nex[j][i];
				}
			}
		}
	}
	int curmn = INF;
	int curind = -1;
	REP(i, n) {
		if (curmn > dp[i][i]) {
			curind = i;
			curmn = dp[i][i];
		}
	}
	if (curind==-1) {
		cout<<"SHIP IT";
	} else {
		cout<<sarr[curind]<<" ";
		int nx = nex[curind][curind];
		while (nx != curind) {
			cout<<sarr[nx]<<" ";
			nx = nex[nx][curind];
		}
	}


	
}