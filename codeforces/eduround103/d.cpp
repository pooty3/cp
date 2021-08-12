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

class UnionFind {
public:
	vi p, setSize; 
	UnionFind(int n) {
		p.assign(n,0);
		REP(i, n) {
			p[i] = i;
		}
		setSize.assign(n,1);
	}
	int findSet(int i) {
		return(p[i]==i) ? i :(p[i] = findSet(p[i]));
	}
	int sizeOfSet(int i) {
		return setSize[findSet(i)];
	}
	void unionSet(int i, int j) {
		int u = findSet(i), v = findSet(j);
		if (u==v) return;
		p[u] = v;

		setSize[v] += setSize[u];
	}
};
void solve() {
	int n;
	cin>>n;
	UnionFind uf(2*n+2);
	string str;
	cin>>str;
	REP(i, n) {
		if (str[i] == 'R') {
			uf.unionSet(2*i, 2*i + 3);
		} else {
			uf.unionSet(2*i+2, 2*i+1);
		}
	}
	REP(i, n+1) {
		cout<<uf.sizeOfSet(i*2)<<" ";
	}cout<<"\n";

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