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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vii parr;
	REP(i, n) {
		int a,s;
		cin>>a>>s;
		parr.push_back({a,2});
		parr.push_back({a+s,1});
	}
	SORT(parr);
	priority_queue<int,vi,greater<int>> pq;
	int amt=0;
	for (auto [t, typ]: parr) {
		if (typ == 1) {
			pq.push(t+m);
		}
		else {
			bool able = false;
			while (!pq.empty()) {
				int t1 = pq.top();pq.pop();
				if (t1 >= t) {
					able = true;
					break;
				}
			}
			amt += able;
		}
	}
	cout<<amt;
}