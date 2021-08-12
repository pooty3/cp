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

void DFS(vvi &arr, bool *barr, int i) {
	barr[i] = true;
	FOREACH(it, arr[i]) {
		if (!barr[*it]) {
			DFS(arr, barr, *it);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vi v;
	vvi arr(n,v);
	bool barr[n];
	memset(barr, 0, sizeof(barr));
	REP(i, m) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
	DFS(arr, barr, 0);
	int va=0;
	REP(i, n) {
		if (!barr[i]) {
			va++;
			cout<<(i+1)<<"\n";
		}
	}
	if (va==0) {
		cout<<"Connected";
	}

}