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
typedef pair<ll,ll> llll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

typedef tuple<int, ll, ll> edge;

const ll INF = 1e18;                             // large enough

class max_flow {
public:
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

struct point {
	ll a,b,c,d;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;
	vector<point> pts(n);
	REP(i, n) {	
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		pts[i] = {a,b,c,d};
	}
	map<pair<ll,ll>, int> mp;
	map<llll, int> mapping;
	vector<pair<llll, llll>> ptss(n);
	REP(i, n) {
		auto [a,b,c,d] = pts[i];
		ll na = a+b;
		ll nx1 = na*d;
		ll ny1 = c*b;
		llll n1 = {nx1/__gcd(nx1,ny1), ny1/__gcd(nx1,ny1)};
		mp[n1]++;
		ll nc = c+d;
		ll nx2 = a*d;
		ll ny2 = nc*b;
		llll n2 = {nx2/__gcd(nx2,ny2), ny2/__gcd(nx2,ny2)};
		mp[n2]++;
		ptss[i] = {n1,n2};
	}
	int ps = mp.size();
	max_flow mf(2+n+ps);
	REP(i, n) {
		mf.add_edge(0, i+1, 1);
	}
	int curind =0;
	for (auto &[fr, c]: mp) {
		mapping.insert({fr,curind});
		mf.add_edge(1+n+curind, 1+n+ps, (c/2)*2);
		curind++;
	}
	REP(i, n) {
		auto [p1,p2] = ptss[i];
		int v = mapping[p1];
		mf.add_edge(i, 1+n+v,1);
		int v2 = mapping[p2];
		mf.add_edge(i, 1+n+v2,1);
	}	
	int c =mf.dinic(0, 1+n+ps);
	cout<<c/2<<"\n";

	REP(i, n) {
		for (auto e: mf.AL[i+1]) {
			//auto []
		}
	} 
}