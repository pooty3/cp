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
	int tot1 =0;
	int tot2 =0;
	vector<map<int,char>> adj(n, map<int,char>());
	REP(i, m) {
		char ch;cin>>ch;
		if (ch == '?') {
			int k;
			cin>>k;
			if (k%2==1) {
				if (tot2 != 0) {
					cout<<"YES\n";
				} else {
					cout<<"NO\n";
				}
			}
			else {
				if (tot1 != 0) {
					cout<<"YES\n";
				} else {
					cout<<"NO\n";
				}
			}
		}
		else if (ch=='+') {
			int u,v;
			char ch;
			cin>>u>>v>>ch;u--;v--;
			adj[u].insert({v, ch});
			if (adj[v].find(u)!=adj[v].end()) {
				if (adj[v][u]==ch) {
					tot1 ++;
				}
				tot2++;
			}
		} 
		else {
			int u,v;
			cin>>u>>v;u--;v--;
			char c1 = adj[u][v];
			adj[u].erase(adj[u].find(v));
			if (adj[v].find(u)!=adj[v].end()) {
				if (adj[v][u]==c1) {
					tot1 --;
				}
				tot2--;
			}
		}
	}
}