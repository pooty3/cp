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
	int totV=0;
	vvi inf(2, vi(3,0));
	REP(i, n) {
		string s;cin>>s;
		REP(j, 3) {
			inf[s[0]=='Y'][j] += s[j+1]=='Y';
		}
		totV += s[0] == 'Y';
	}
	REP(i, 3) {
		if (inf[0][i]*totV<= (n-totV)*inf[1][i]) {
			cout<<"Not Effective\n";
		} else {
			ld d = 100 - (ld)(n-totV)*(ld)inf[1][i]/(ld)totV/(ld)inf[0][i]*100;
			cout<<setprecision(10)<<d<<"\n";
		}
	}

}