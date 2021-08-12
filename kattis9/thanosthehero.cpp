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
	int n;cin>>n;
	vll arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	bool able = true;
	ll tot =0;
	for (int i=n-2; i>=0;--i) {
		if (arr[i]<arr[i+1])continue;
		if (arr[i+1] == 0) {
			able = false;
			break;
		}
		tot += arr[i]-(arr[i+1]-1);
		arr[i] = arr[i+1]-1;
	}
	tot = able? tot:1;
	cout<<tot;
}