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
	ld tot=0;
	int n;
	cin>>n;
	vll t(n);
	vector<ld> amt(n);
	REP(i, n) {
		ld c;
		cin>>t[i]>>amt[i];
	}
	REP(i, n-1) {
		tot += (t[i+1]-t[i])*(amt[i+1]+amt[i]);
	}
	//cout<<tot;
	cout<<setprecision(10)<<(ld)tot/2000.0<<"\n";

}