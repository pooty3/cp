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

void incre(string &s, int u) {
	s[u] = (char)((s[u] -'0' + 1)%4 +'0');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	REP(i, 9) {
		string x;
		cin>>x;
		s += x;
	}
	map<string, int> dist;
	dist[s] = 0;
	queue<string> q;
	q.push(s);
	while (!q.empty()) {
		auto u = q.front();q.pop();
		REP(i, 9) {
			string v = u;
			int r = i/3;
			int c = i%3;
			REP(j, 3) {
				incre(v, r*3 + j);
			}
			REP(j, 3) {
				if (j == r) continue;
				incre(v,j*3+c);
			}
			if (dist.find(v)==dist.end()) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	string final = "000000000";
	if (dist.find(final) == dist.end()) {
		cout<<-1;
	} else {
		cout<<dist[final];
	}
}