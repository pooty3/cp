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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	vi tarr(1000001, 1);
	REPL(i, 1, 1000001) {
		tarr[i] = tarr[i-1]*2;
		tarr[i]%=10;
	}
	vi ans(1000001, 1); 
	int cur = 1;
	int cu2 = 0;
	int cu5 =0;
	REPL(i, 1, 1000001) {
		int t = i;
		while (t%5==0) {
			t/=5;
			cu5++;
		}
		while(t%2==0) {
			t/=2;
			cu2++;
		}
		cur *= t;
		cur %=10;
		ans[i] = cur * tarr[cu2-cu5];
		ans[i]%=10;
	}
	while (true) {
		int n;cin>>n;
		if (n==0) break;
		cout<<ans[n]<<"\n";
	}
}