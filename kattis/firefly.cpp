#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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
	int n,h;
	cin>>n>>h;
	vi barr(n/2);
	vi tarr(n/2);
	REP(i, n/2) {
		cin>>barr[i]>>tarr[i];
	}
	sort(barr.begin(), barr.end());
	sort(tarr.begin(), tarr.end());
	int m = INF;
	int c=0;
	REPL(i,1, h+1) {
		int o = (int)(barr.end()- lower_bound(barr.begin(), barr.end(), i))+
				(int)(tarr.end()-lower_bound(tarr.begin(), tarr.end(), h-i+1));
		if (o < m) {
			c=1;
			m=o;
		} else if (o==m) {
			c++;
		} else {

		}
	}
	cout<<m<<" "<<c;


}