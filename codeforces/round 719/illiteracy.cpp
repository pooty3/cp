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

void rot(string &s, int pos) {
	if (pos<0||pos>=s.length()) {
		return;
	}
	if (s[pos] == 'F') {
		s[pos] = 'A';
	} else {
		s[pos] ++;
	}
}

void modi(string &v, int i) {
	switch (v[i]){
				case 'A':
				rot(v, i-1);
				rot(v, i+1);
				break;
				case 'B':
				if (i != 0 && i != 7) {
					v[i+1] = v[i-1];
				}
				break;
				case 'C':
				rot(v, 7-i);
				break;
				case 'D':
				if (i<4) {
					REP(j, i) {
						rot(v,j);
					}
				} else {
					REPL(j, i+1, 8) {
						rot(v,j);
					}
				}
				break;
				case 'E':
				if (i != 0 && i != 7) {
					int y = i<4?i: 7-i;
					rot(v, i-y);
					rot(v, i+y);
				}
				break;
				case 'F':
				if (i%2==1) {
					rot(v, (i+1)/2-1);
				} else {
					rot(v, (i+10)/2 -1);
				}
				break;
			}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s,d;
	cin>>s>>d;
	map<string, int> dist;
	dist[s] = 0;
	queue<string> q;
	q.push(s);
	while (!q.empty()) {
		auto u = q.front(); q.pop();;
		if (u==d) break;
		REP(i, 8) {
			string v = u;
			modi(v, i);
			if (dist.find(v)==dist.end()) {
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
	cout<<dist[d];
}