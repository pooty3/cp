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
	ll m,n,s;
	cin>>m>>n>>s;
	vll dist(m, -1);
	vll aarr(n), barr(n);
	REP(i,n) {
		cin>>aarr[i]>>barr[i];
	}
	queue<ll> q;
	dist[s] =0;
	q.push(s);
	while (!q.empty()) {
		ll u = q.front(); q.pop();
		REP(i, n) {
			int v = (u*aarr[i] + barr[i])%m;
			if (dist[v]==-1) {
				dist[v] = dist[u]+1;
				q.push(v);
			}	
		}
	}
	cout<<dist[0];
}