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

class UnionFind{
public:
	vi p;
	UnionFind(int n) {
		p.assign(n, 0);
		REP(i,n) {p[i] =i;}
	}
	int findSet(int n) {
		return (p[n]==n) ? n: (p[n]= findSet(p[n]));
	}
	bool merge(int i, int j) {
		if (findSet(i)!=findSet(j)) {
			p[findSet(i)] = findSet(j);		
			return true;
		} else {
			return false;
		} 
	}
};

void solve() {
	int m,c;
	cin>>m>>c;
	UnionFind uf(c);
	vector<tuple<double, int, int>> ed;
	REP(i, c*(c-1)/2) {
		int u,v,w; cin>>u>>v>>w;
		ed.push_back({w,u,v});

	}
	int tot = c;
	sort(ed.begin(), ed.end());
	for (auto &[w, u, v] : ed) {
		if (uf.merge(u,v)) {
			tot += w;
			if (tot > m) {
				break;
			}
		}
	}
	if (tot <=m) {
		cout<<"yes\n";
	} else {
		cout<<"no\n";
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}