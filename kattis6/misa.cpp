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
	int r,s;
	cin>>r>>s;
	vector<string> arr(r);
	REP(i, r) {
		cin>>arr[i];
	}
	int totc =0;
	int curmx =0;
	REP(i, r) {
		REP(j, s) {
			int c =0;
			REPL(k, -1, 2) {
				REPL(l, -1, 2) {
					if (k==0&&l==0) continue;
					int ni = i+k;
					int nj= j+l;
					if (ni<0||ni==r||nj<0||nj==s) continue;
					c += arr[ni][nj] == 'o';
				}
			}
			if (arr[i][j] == 'o') {
				totc+=c;
			} else {
				curmx = max(curmx,c);
			}
		}
	}
	cout<<totc/2+curmx;

}