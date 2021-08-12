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

int mod(int a, int m) {                          // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}

int modPow(int b, int p, int m) {                // assume 0 <= b < m
  if (p == 0) return 1;
  int ans = modPow(b, p/2, m);                   // this is O(log p)
  ans = mod(ans*ans, m);                         // double it first
  if (p&1) ans = mod(ans*b, m);                  // *b if p is odd
  return ans;                                    // ans always in [0..m-1]
}

int extEuclid(int a, int b, int &x, int &y) {    // pass x and y by ref
  int xx = y = 0;
  int yy = x = 1;
  while (b) {                                    // repeats until b == 0
    int q = a/b;
    tie(a, b) = tuple(b, a%b);
    tie(x, xx) = tuple(xx, x-q*xx);
    tie(y, yy) = tuple(yy, y-q*yy);
  }
  return a;                                      // returns gcd(a, b)
}

ll modInverse(int b, int m) {                   // returns b^(-1) (mod m)
  int x, y;
  int d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
  if (d != 1) return -1;                         // to indicate failure
  // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
  return mod(x, m);
}
int md = 1e9+7;
vvll chances(201, vll(201, -1));
ll findchance(int a, int b) {
	if (chances[a][b] == -1) {
		if (a==0) {
			chances[a][b] = 1;
		} else if (b== 0) {
			chances[a][b] = 0;
		} else {
			ll c1 = findchance(a-1, b);
			ll c2 = findchance(a, b-1);
			ll totc = (c1 * modInverse(2, md) + c2 * modInverse(2, md))%md ;
			chances[a][b] = totc;
		}
	} 
	return chances[a][b];
}

int findcommonances(int u, int v, vector<unordered_set<int>> &gp, vvi &commonances, vi &pr) {
	if (commonances[u][v] == -1) {
		if (gp[u].find(v)!= gp[u].end()) {
			commonances[u][v] = v;
		} else if (gp[v].find(u)!=gp[v].end()) {
			commonances[u][v] = u;
		} else {
			commonances[u][v] = findcommonances(pr[u], v, gp, commonances, pr);
		}
		commonances[v][u] = commonances[u][v];
	}
	return commonances[u][v];
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vvi adj(n,vi());
	REP(i, n-1) {
		int u,v;cin>>u>>v;u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll totC =0;
	REP(i, n) {
		vi dist(n, INF);
		vector<unordered_set<int>> gp(n, unordered_set<int>());
		vi p(n, -1);
		dist[i] = 0;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto v: adj[u]) {
				if (dist[v] == INF) {
					p[v] = u;
					dist[v] = dist[u] + 1;
					for (auto ttt: gp[u]) {
						gp[v].insert(ttt);
					}
					gp[v].insert(u);
					q.push(v);
				}
			}
		}
		vvi commonances(n, vi(n, -1));
		REP(j, n) {
			REP(k, j) {
				int ances = findcommonances(j, k, gp, commonances, p);
				totC += findchance(dist[j]-dist[ances], dist[k] - dist[ances]);
				totC %= md;
			} 
		}
	}
	cout<<(totC * modInverse(n, md))%md;
}