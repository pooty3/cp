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

int main()
{
	int n;
	cin>>n;
	vvi arr(n, vi());
	cout<<"? "<<1<<endl;
	vii edgs;
	REP(i, n) {
		int x;
		cin>>x;
		arr[x].push_back(i+1);
		if (x==1) {
			edgs.push_back({1, i+1});
		}
	}
	int odds = 0;
	int evens = 0;
	REPL(i,1, n) {
		if (i%2==0) {
			evens+= arr[i].size();
		} else {
			odds+=arr[i].size();
		}
	}
	for (int i = evens>odds? 1: 2; i<n; i+=2) {
		for (auto v: arr[i]) {
			cout<<"? "<<v<<endl;
			REP(i, n) {
				int x;
				cin>>x;
				if (i==0) continue;
				if (x==1) {
					edgs.push_back({v, i+1});
				}
			}
		}
	}
	cout<<"!"<<endl;
	for (auto &[u,v]: edgs) {
		cout<<u<<" "<<v<<endl;
	}
}