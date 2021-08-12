#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 1e9 + 7
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

void solve() {
	int n,m;
	cin>>n>>m;
	vector<multiset<int>> arr(n);
	REP(i, n) {
		REP(j, m) {
			int x;
			cin>>x;
			arr[i].insert(x);
		}
	}
	vvi darr(n, vi(m));
	REP(z, m) {
		int curb = INF;
		int curind = -1;
		REP(i, n) {
			if (curb> *arr[i].begin()) {
				curb = *arr[i].begin();
				curind = i;
			}
		}
		REP(i, n) {
			if (i == curind) {
				darr[i][z] = *arr[i].begin();
				arr[i].erase(arr[i].begin());
			} else {
				darr[i][z] = *arr[i].rbegin();
				arr[i].erase(prev(arr[i].end()));
			}
		}
	}	
	REP(i, n) {
		REP(j, m) {
			cout<<darr[i][j]<<" ";
		}cout<<"\n";
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}