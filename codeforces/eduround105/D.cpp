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

struct node {
	int sal;
	int parent;
	set<int> descendant;
};
vector<node> nodes;
int findgranddad(int n) {
	if (nodes[n].parent == -1) {
		return n;
	} else {
		return findgranddad(nodes[n].parent);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vvi arr(n, vi(n,0));
	REP(i, n) {
		REP(j,n) {
			cin>>arr[i][j];
		}
	}
	int head;
	set<ii> toprocess;
	REP(i, n) {
		nodes.push_back({arr[i][i], -1, set<int>()});
		nodes[i].descendant.insert(i);
		toprocess.insert({arr[i][i], i});
	}
	while (!toprocess.empty()) {
		auto &[cursal, u] = *toprocess.begin();
		toprocess.erase(toprocess.begin());
		int mn = INF;
		int shared=-1;
		FOREACH(it, nodes[u].descendant) {
			REP(i, n) {
				int curv = arr[*it][i];
				if (curv < mn && curv > cursal) {
					mn = curv;
					shared = -1;
					int gdind = findgranddad(i);
					if (gdind!=-1 && nodes[gdind].sal == mn) {
						shared = i;
					}
				} else if (curv == mn) {
					int gdind = findgranddad(i);
					if (gdind!=-1 && nodes[gdind].sal == mn) {
						shared = i;
					}
				} else {}
			}
		}
		if (mn == INF) {
			head = u;
			continue;
		} 
		bool found = false;
		if (shared != -1) {
		REP(i, nodes.size()) {
			if (nodes[i].sal == mn) {
				if (nodes[i].descendant.find(shared)!= nodes[i].descendant.end()) {
					found = true;
					FOREACH(it2, nodes[u].descendant) {
						nodes[i].descendant.insert(*it2);
						nodes[u].parent = i;
					}
					break;
				}
			}
		}
	}
		if (!found) {
			nodes.push_back({mn, -1, set<int>()});
			FOREACH(it2, nodes[u].descendant) {
				nodes[nodes.size()-1].descendant.insert(*it2);
			}
			nodes[u].parent = nodes.size()-1;
			toprocess.insert({mn, nodes.size()-1});
		}
	}
	cout<<nodes.size()<<"\n";
	REP(i, nodes.size()) {
		cout<<nodes[i].sal<<" ";
	}
	cout<<"\n"<<(head+1)<<"\n";
	REP(i, nodes.size()) {
		if (i == head) continue;
		cout<<(i+1)<<" "<<(nodes[i].parent+1)<<"\n";
	}
}