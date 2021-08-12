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
	int n;
	cin>>n;
	vvi chess(n, vi(n, -1));
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	REP(i, n) {
		ii s = {i, i};
		stack<ii> st;
		st.push(s);
		REP(zz, arr[i]) {
			if (st.empty()) {
				cout<<-1;
				return 0;
			}
			auto [r,c] = st.top(); st.pop();
			chess[r][c] = arr[i];
			if (r != n-1) {
				st.push({r+1,c});
			}
			if (c != 0 && chess[r][c-1] == -1) {
				st.push({r,c-1});
			}
		}
	}
	REP(i, n) {
		REP(j, i+1) {
			cout<<chess[i][j]<<" ";
		}cout<<"\n";
	}
}