#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384

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
typedef tuple<int, ll, ll> edge;
typedef double ld;
const ll INF = 1e18;                             // large enough

class max_flow {
private:
  int V;
  vector<edge> EL;
  vector<vi> AL;
  vi d, last;
  vector<ii> p;

  bool BFS(int s, int t) {                       // find augmenting path
    d.assign(V, -1); d[s] = 0;
    queue<int> q({s});
    p.assign(V, {-1, -1});                       // record BFS sp tree
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;                         // stop as sink t reached
      for (auto &idx : AL[u]) {                  // explore neighbors of u
        auto &[v, cap, flow] = EL[idx];          // stored in EL[idx]
        if ((cap-flow > 0) && (d[v] == -1))      // positive residual edge
          d[v] = d[u]+1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
      }
    }
    return d[t] != -1;                           // has an augmenting path
  }

  ll send_one_flow(int s, int t, ll f = INF) {   // send one flow from s->t
    if (s == t) return f;                        // bottleneck edge f found
    auto &[u, idx] = p[t];
    auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
    ll pushed = send_one_flow(s, u, min(f, cap-flow));
    flow += pushed;
    auto &rflow = get<2>(EL[idx^1]);             // back edge
    rflow -= pushed;                             // back flow
    return pushed;
  }

  ll DFS(int u, int t, ll f = INF) {             // traverse from s->t
    if ((u == t) || (f == 0)) return f;
    for (int &i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
      auto &[v, cap, flow] = EL[AL[u][i]];
      if (d[v] != d[u]+1) continue;              // not part of layer graph
      if (ll pushed = DFS(v, t, min(f, cap-flow))) {
        flow += pushed;
        auto &rflow = get<2>(EL[AL[u][i]^1]);     // back edge
        rflow -= pushed;
        return pushed;
      }
    }
    return 0;
  }

public:
  max_flow(int initialV) : V(initialV) {
    EL.clear();
    AL.assign(V, vi());
  }

  // if you are adding a bidirectional edge u<->v with weight w into your
  // flow graph, set directed = false (default value is directed = true)
  void add_edge(int u, int v, ll w, bool directed = true) {
    if (u == v) return;                          // safeguard: no self loop
    EL.emplace_back(v, w, 0);                    // u->v, cap w, flow 0
    AL[u].push_back(EL.size()-1);                // remember this index
    EL.emplace_back(u, directed ? 0 : w, 0);     // back edge
    AL[v].push_back(EL.size()-1);                // remember this index
  }

  ll edmonds_karp(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V*E^2) algorithm
      ll f = send_one_flow(s, t);                // find and send 1 flow f
      if (f == 0) break;                         // if f == 0, stop
      mf += f;                                   // if f > 0, add to mf
    }
    return mf;
  }

  ll dinic(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V^2*E) algorithm
      last.assign(V, 0);                         // important speedup
      while (ll f = DFS(s, t))                   // exhaust blocking flow
        mf += f;
    }
    return mf;
  }
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m,p;cin>>n>>m>>p;
	max_flow mf(n+m+p+2);
	REP(i, n) {
		int k;cin>>k;
		mf.add_edge(1+p+m+i, n+m+p+1,1);
		REP(j, k) {
			int v;cin>>v;
			mf.add_edge(p+v, 1+p+m+i, 1);
		}
	}
	set<int> cat;
	REP(i, p) {
		int l;cin>>l;
		REP(j, l) {
			int v;cin>>v;
			mf.add_edge(i+1, v+p,1);
			cat.insert(v-1);
		}
		int r;cin>>r;
		mf.add_edge(0, i+1, r);
	}
	REP(i, m) {
		if (cat.find(i)==cat.end()){
			mf.add_edge(0, i+1+p, 1);
		}
	}	

	cout<<mf.dinic(0, n+m+p+1);
}