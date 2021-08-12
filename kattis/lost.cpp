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
	int n,m;
	cin>>n>>m;
	map<string, int> mp;
	mp.insert({"English", 0});
	REP(i, n) {
		string s;
		cin>>s;
		mp.insert({s,i+1});
	}
	vector<vii> adj(n+1, vii());
	REP(i,m) {
		string s1, s2;
		int co;
		cin>>s1>>s2>>co;
		adj[mp[s1]].push_back({mp[s2], co});
		adj[mp[s2]].push_back({mp[s1], co});
	}
	vi dist(n+1, INF);
	vi co(n+1, INF);
	bool pro[n+1];
	memset(pro, 0 , sizeof(pro));
	dist[0] =0;
	co[0] =0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (!pro[u]) {
			pro[u] = true;
			for (auto &[v, w] : adj[u]) {
				if (dist[v] >= dist[u] + 1) {
					dist[v] = dist[u] +1;
					co[v] = min(co[v], w);
					q.push(v);
				}
			}
		}
	}
	bool possible = true;
	int tot =0; 
	FOREACH(it, co) {
		if (*it == INF) {
			possible = false;
			break;
		} else {
			tot += *it;
		}
	} 
	if (possible) {
		cout<<tot<<endl;
	} else {
		cout<<"Impossible"<<endl;
	}
}