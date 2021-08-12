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
	int numSet;
	vi p;
	UnionFind(int n) {
		numSet = n;
		p.assign(n, 0);
		REP(i,n) {p[i] =i;}
	}
	int findSet(int n) {
		return (p[n]==n) ? n: (p[n]= findSet(p[n]));
	}
	void merge(int i, int j) {
		if (findSet(i)!=findSet(j)) {
			p[findSet(i)] = findSet(j);	
			numSet--;	
		}
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	vector<string> arr(n);
	REP(i, n){
		cin>>arr[i];
	}
	UnionFind uf(k);
	REP(i, m) {
		REP(j, n) {
			uf.merge(arr[0][i]-'A', arr[j][i]-'A');
		}
	}
	cout<<uf.numSet;

}