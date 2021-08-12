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

void ddd() {
	cout<<0;exit(0);
}
int main()

{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vector<string> arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	REP(i,n) {
		int cur =0;
		int curc = 1;
		REP(j, n) {
			if (arr[i][j]=='W') cur++;
			if (j==0) continue;
			if (arr[i][j-1] == arr[i][j]) {
				curc++;
				if (curc ==3) ddd();
			} else {
				curc=1;
			}
		}
		if (cur*2!=n) {
			ddd();
		}
	}
	REP(i,n) {
		int cur =0;
		int curc = 1;
		REP(j, n) {
			if (arr[j][i]=='W') cur++;
			if (j==0) continue;
			if (arr[j-1][i] == arr[j][i]) {
				curc++;
				if (curc ==3) ddd();
			} else {
				curc=1;
			}
		}
		if (cur*2!=n) {
			ddd();
		}
	}
	cout<<1;

}