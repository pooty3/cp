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
	int f,s,g,u,d;cin>>f>>s>>g>>u>>d;
	vi dist(f+1,INF);
	dist[s] =0;
	queue<int> q;
	q.push(s);
	vi arr = {u, -d};
	while (!q.empty()) {
		int u = q.front();q.pop();
		REP(i, 2) {
			int v = u + arr[i];
			if (v<0||v>f||dist[v]!=INF) continue;
			dist[v] = dist[u] +1;
			q.push(v);
		}
	}
	if (dist[g] == INF) {
		cout<<"use the stairs";
	} else {
		cout<<dist[g];
	}
}