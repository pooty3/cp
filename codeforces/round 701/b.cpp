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
	int n,q,k;
	cin>>n>>q>>k;
	vi arr(n+2);
	vll cularr(n+1,0);
	vi diffarr(n);
	arr[0] = 0;
	arr[n+1] = k+1;
	REP(i, n) {
		cin>>arr[i+1];
	}
	REP(i, n) {
		diffarr[i] = arr[i+2]-arr[i]-2;
	}

	REPL(i,1, n) {
		cularr[i] = cularr[i-1]+ diffarr[i-1];
	}
	REP(i, q) {
		int l,r;
		cin>>l>>r;
		if (l==r) {
			cout<<(k-1)<<"\n";
		} else {
			cout<<cularr[r-1] - cularr[l] + arr[l+1]-2 + (k-arr[r-1]-1)<<"\n";
		}
	}

}