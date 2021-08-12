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

vi rdir = {0,0,0,-1,1};
vi cdir = {0,1,-1,0,0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vi dist((1<<9),INF);
	dist[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();q.pop();
		REP(j, 9) {
			int r = j/3;
			int c = j%3;
			int curv = u;
			REP(i, 5) {
				int nr = r + rdir[i];
				int nc = c + cdir[i];
				if (nr<0 || nr>=3 ||nc<0||nc>=3) continue;
				int grid = nr*3 + nc;
				curv ^= (1<<grid);
			}
			if (dist[curv]==INF) {
				dist[curv] = dist[u] +1;
				q.push(curv);
			}
		}
	}
	int p;cin>>p;
	REP(zz, p) {
		int cur =0;
		string s="";
		REP(i, 3) {
			string ss;
			cin>>ss;
			s += ss;
		}
		REP(i,9) {
			if (s[i] == '*') {
				cur += (1<<i);
			}
		}
		cout<<dist[cur]<<"\n";
	}
}