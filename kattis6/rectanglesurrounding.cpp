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
	while (true){
	int n;
	cin>>n;
	if (n==0) break;
	bool arr[500][500];
	memset(arr, 0, sizeof(arr));
	REP(z, n) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		REPL(i, a,c) {
			REPL(j, b,d) {
				arr[i][j] = 1;
			}
		}
	}
	int c=0;
	REP(i, 500) {
		REP(j, 500) {
			c+=arr[i][j];
		}
	}
	cout<<c<<"\n";}
}