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
typedef tuple<int, int,int> edge;
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

  bool unionSet(int i, int j) {
    if (isSameSet(i, j)) return false;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;          
    return true;                         // a union reduces numSets
  }
};

int diff(string &s1, string &s2) {
	int tot =0;
	REP(i, s1.length()) {
		tot += s1[i]!= s2[i];
	}return tot;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	vector<string> arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	vector<edge> EL;
	REP(i, n) {
		REP(j, n) {
			EL.push_back({diff(arr[i], arr[j]),i,j});
		}
	}
	SORT(EL);
	int tot =0;
	UnionFind uf(n);
	vii p;
	for (auto [w, u,v]: EL) {
		if (uf.unionSet(u,v)) {
			p.push_back({u,v});
			tot +=w;
		}
	}
	cout<<tot<<"\n";
	for (auto [u,v]:p) {
		cout<<u<<" "<<v<<"\n";
	}

}