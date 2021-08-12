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
void solve() {
	int tc, n;
	cin>>tc>>n;
	vll arr = {0,0};
	for (char ch: to_string(n)) {
		int v = ch-'0';
		arr[0]*=8;
		arr[1]*=16;
		if (v<8) {
			arr[0] += v;
		} else {
			arr[0] = -1;
		}
		arr[1] +=v;
	}
	arr[0] = max(0LL, arr[0]);
	cout<<tc<<" "<<arr[0]<<" "<<n<<" "<<arr[1]<<"\n";

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