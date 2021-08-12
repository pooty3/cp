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
	ll l,d;
	int n;
	cin>>l>>d;
	cin>>n;
	vll arr(n+2);
	REP(i, n) {
		cin>>arr[i];
	}
	arr[n] = 6-d;
	arr[n+1] = l-6+d;
	SORT(arr);

	ll tot =0;
	REPL(i, 1, n+2) {
		tot += (arr[i]-arr[i-1])/d -1;

	}
	cout<<tot;

}