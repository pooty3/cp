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

int main()
{
	int n, t;
	cin>>n>>t;
	vi v;
	vvi arr(t, v);
	REP(i, n) {
		int c,ti;
		cin>>c>>ti;
		arr[ti].push_back(c);
	}
	int tot =0;
	priority_queue<int> pq;
	for (int i = t-1; i>=0 ; i--) {
		FOREACH(it, arr[i]) {
			pq.push(*it);
		}
		if (!pq.empty()) {
			tot += pq.top();
			pq.pop();
		}
	}
	cout<<tot;
	

}