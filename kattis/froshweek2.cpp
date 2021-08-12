#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end());
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
	int n,m;
	cin>>n>>m;
	vi tarr(n), marr(m);
	REP(i, n) {
		cin>>tarr[i];
	}
	REP(i, m) {
		cin>>marr[i];
	}

	SORT(tarr);
	SORT(marr);
	int tot =0;
	int i=0,j=0;
	while (true) {
		if (i == tarr.size()) break;
		if (j == marr.size()) break;
		if (tarr[i]<= marr[j]) {
			i++;
			j++;
			tot++;
		} else {
			j++;
		}
	}
	cout<<tot;
}