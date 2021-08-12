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

int counter=0;
vi dfs_num, dfs_low, onstack;
int maxsize=0;
stack<int> stk;
void tarjanSCC(vvi &adj, int n) {
	dfs_num[n]=dfs_low[n]= counter;
	counter++;
	stk.push(n);
	onstack[n] = 1;
	FOREACH(it, adj[n]) {
		if (dfs_num[*it]==-1) {
			tarjanSCC(adj, *it);
		} 
		if (onstack[*it]) {
			dfs_low[n]= min(dfs_low[n], dfs_low[*it]);
		}
	}
	if (dfs_low[n]== dfs_num[n]) {
		int cursize=0;
		while (true) {
			int v = stk.top();
			onstack[v] = 0;
			stk.pop();
			cursize++;
			if (n==v) {
				break;
			}
		}
		maxsize = max(cursize, maxsize);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vi speak(n);
	vector<set<int>> under(n, set<int>());
	map<string, int> lang;
	string str;
	int langco = 0;
	getline(cin, str);
	REP(i, n) {
		getline(cin, str);
		stringstream s(str);
		s>>str;
		s>>str;
		if(lang.find(str)==lang.end()) {
			lang.insert({str, langco});
			langco++;
		}
		speak[i] = lang[str];
		under[i].insert(lang[str]);
		while (s>>str) {
			if (lang.find(str)==lang.end()) {
				lang.insert({str, langco});
				langco++;
			}
			under[i].insert(lang[str]);
		}
	}
	vvi adj (n, vi());
	REP(i, n) {
		REP(j, n) {
			if (i!=j&& under[j].find(speak[i])!=under[j].end()) {
				adj[i].push_back(j);
			}
		}
	}
	dfs_num.assign(n, -1);
	dfs_low.assign(n, -1);
	onstack.assign(n, 0);
	REP(i, n) {
		if (dfs_num[i]==-1) {
			tarjanSCC(adj, i);
		}
	}
	cout<<(n- maxsize);

}