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
	int h,w,n,m;cin>>h>>w>>n>>m;
	vvi arr(h, vi(w));
	REP(i, h){
		REP(j, w) {
			cin>>arr[i][j];
		}
	}
	vvi ker(n, vi(m));
	REP(i, n){
		REP(j, m) {
			cin>>ker[n-1-i][m-1-j];
		}
	}
	vvi res(h-n+1, vi(w-m+1));
	REP(i, h-n+1) {
		REP(j,w-m+1) {
			int cur =0;
			REP(ii, n) {
				REP(jj,m) {
					cur += arr[i+ii][j+jj]*ker[ii][jj];
				}
			}
			res[i][j] = cur;
		}
	}
	for (auto &vv: res) {
		for(auto i: vv) {
			cout<<i<<" ";
		}
		cout<<"\n";
	}
}