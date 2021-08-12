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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int k,n;
	while(cin>>k>>n) {
		vector<vector<long double>> arr(n, vector<long double>(k+1,0));
		REP(i, k+1) {
			arr[0][i] = 1;
		}
		REPL(i, 1, n) {
			REP(j, k+1) {
				arr[i][j] = arr[i-1][j];
				if (j>0) arr[i][j] +=arr[i-1][j-1];
				if (j<k) arr[i][j] +=arr[i-1][j+1];
			}
		}
		long double tot = 0;
		REP(i, k+1) {
			tot+= arr[n-1][i];
		}
		long double over= pow(k+1,n);
		cout<<setprecision(10)<<(tot*100/over)<<"\n";

	}

}