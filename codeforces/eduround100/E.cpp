#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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

bool visited[1000000];

class UnionFind {
public:
	vi p;
	UnionFind(int n) {
		p.assign(n, 0);
		REP(i, n) {
			p[i] =i;
		}
	}

	int findparent(int k) {
		if (k!=p[k]) {
			int c = findparent(p[k]);
			p[k] = c;
			return c;
		} else {
			return k;
		}
	}
	bool sameset(int k, int j) {
		return findparent(k)==findparent(j);

	}
	void merge(int k, int v) {
		if (sameset(k, v)) {
			return;}
		p[k] = v;
	}
};

void toposortutil (vvi &adjlist, stack<int> &s, int i) {
	visited[i] = true;
	REP(j, adjlist[i].size()) {
		if (!visited[adjlist[i][j]]) {
			toposortutil(adjlist, s, adjlist[i][j]);
		}
	}
	s.push(i);
}
void toposort(vvi &adjlist, stack<int> &s) {
	REP(i, adjlist.size()) {
		if (!visited[i]) {
			toposortutil(adjlist, s, i);
		}
			
	}
}
int main()
{
	int n,k;
	cin>>n>>k;
	vii arr1;
	REP(i, n) {
		int x;
		cin>>x;
		arr1.push_back({x, i+1});
	}
	bool wrong = false;
	vi narr(n+1,-1);
	vi barr(n+1,-1);
	UnionFind uf(n+1);
	REP(i, k) {
		int x,y;
		cin>>x>>y;
		if (uf.sameset(x,y) ||narr[x]!=-1||barr[y]!=-1) {
			wrong = true;
		} else {
			narr[x]=y;
			barr[y]=x;
			uf.merge(x,y);
		}
	}
	if (wrong) {
		cout<<0;
	} else {
		vi parr(n+1, -1);
		vvi mp;
		int ind=0;
		REP(i, n+1) {
			if (parr[i]==-1) {
				int p=i;
				while (barr[p]!=-1) {
					p = barr[p];
				}
				vi arr;
				while(narr[p]!=-1) {
					arr.push_back(p);
					parr[p] = ind;
					p = narr[p];
				}
				arr.push_back(p);
				parr[p] = ind;
				mp.push_back(arr);
				ind++;			
			}
		}
		vi vv;
		vvi adjlist(ind,vv);
		REP(i, n) {
			int u = parr[arr1[i].first];
			int v = parr[arr1[i].second];
			if (u!=v) {
				adjlist[u].push_back(v);
			}
		}
		memset(visited, 0, sizeof(visited));
		stack<int> s;
		toposort(adjlist, s);
		vi sarr;
		unordered_map<int, int> mp2; 
		int index=0;
		while(!s.empty()) {
			int st = s.top();
			s.pop();
			FOREACH(it, mp[st]) {
				int c = *it;
				sarr.push_back(c);
				mp2.insert({c, index});
				index++;
			}
		}
		bool valid = true;
		REP(i,n) {
			int u = arr1[i].first;
			int v = arr1[i].second;
			if (mp2[u]> mp2[v]) {
				valid = false;
				break;
			}
		}
		if (valid) {
			FOREACH(it, sarr) {
				if ((*it)!=0) {
					cout<<(*it)<<" ";
				}
			}
		} else {
			cout<<0;
		}
	}


}