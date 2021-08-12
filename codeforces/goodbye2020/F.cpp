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

class UnionFind {
public:
	vi p, setSize, setSwitch;
	UnionFind(int n) {
		p.assign(n, 1);
		REP(i, n) {
			p[i] =i;
		}
		setSize.assign(n, 1);
		setSwitch.assign(n, 0);
	}
	int findSet(int i) {
		return (p[i]==i)? i :(p[i]= findSet(p[i]));
	}

	void unionSet(int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x!=y) {
			p[x] = y;
		
			setSize[y] += setSize[x];
			setSwitch[y] += setSwitch[x];
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vi arr;
	UnionFind uf(m);
	REP(i, n) {
		int c;
		cin>>c;
		if (c==1) {
			int x;cin>>x;x--;
			int c = uf.findSet(x);
			if (uf.setSize[c]!=uf.setSwitch[c]) {
				arr.push_back(i);
				uf.setSwitch[c]++;
			}
		} else {
			int x,y;
			cin>>x>>y;x--;y--;
			int s1 = uf.findSet(x);
			int s2 = uf.findSet(y);
			if (s1!=s2) {
				if (uf.setSize[s1]!=uf.setSwitch[s1] || uf.setSize[s2]!=uf.setSwitch[s2]) {
					uf.unionSet(s1,s2);
					int c = uf.findSet(s1);
					arr.push_back(i);
					uf.setSwitch[c]++;
				}
			}
		}
	}
	int tot =1;
	REP(i, arr.size()) {
		tot = tot * 2;
		tot %= (int)(1e9 + 7);
	}
	cout<<tot<<" "<<arr.size()<<"\n";
	REP(i, arr.size()) {
		cout<<(arr[i]+1)<<" ";
	}

}