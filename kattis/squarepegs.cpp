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
	int n,m,k;
	cin>>n>>m>>k;
	vi sarr(n), harr(m+k);
	REP(i, n) {
		cin>>sarr[i];
	}
	REP(i, m) {
		cin>>harr[i];
	}
	REP(i, k) {
		int l;
		cin>>l;
		double a = l*l;
		a = sqrt(a/2);
		harr[m+i] = floor(a);
	}
	SORT(sarr);
	SORT(harr);
	int tot=0;
	int i=0,j=0;
	while (true) {
		if (i==n || j== m+k) break;
		if (harr[j] < sarr[i]) {
			j++;
			i++;
			tot++;
		} else {
			i++;
		}

	}
	cout<<tot;




}