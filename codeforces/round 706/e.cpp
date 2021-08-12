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

class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};
vi udir = {-1,1,0,0};
vi vdir = {0,0,-1,1};
void solve() {
	int n,m;
	cin>>n>>m;
	vector<string> arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	vvi narr(n, vi(m, -1));
	int cur=0;
	queue<pair<ii, int>> grow;
	REP(i, n) {
		REP(j, m) {
			if (arr[i][j]=='X') {
				narr[i][j] = cur;
				cur++;
				grow.push({{i,j-1}, 0});
				grow.push({{i+1,j}, 1});
				grow.push({{i,j+1}, 2});
				grow.push({{i-1,j}, 3});
			}
		}
	}
	UnionFind uf(cur);
	while (!grow.empty()) {
		auto &[p, dir] = grow.front(); grow.pop();
		auto &[x,y] = p;
		if (x<0||x>=m||y<0||y>=n) {
			continue;
		}
		if (arr[x][y]!=)
		bool able = true;
		set<int> s;
		s.insert(uf.findSet(narr[x][y]));
		REP(i, 4) {
			if ()
		}

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