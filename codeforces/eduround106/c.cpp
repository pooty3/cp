#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 9999999999999999
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

void solve() {
	int n;
	cin>>n;
	vll arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	int lcur = n;
	int lcurbest = arr[0];
	int rcur = n;
	int rcurbest = arr[1];
	ll minc = n*(arr[0] + arr[1]);
	ll curc = minc;
	REPL(i, 2, n) {
		if (i%2 == 0) {
			if (arr[i] >= lcurbest) {
				curc += (arr[i] - lcurbest);
				lcur--;
			} else {
				curc += (arr[i] - lcurbest) * (lcur -1);
				lcur--;
				lcurbest = arr[i];
			}
		} else {
			if (arr[i] >= rcurbest) {
				curc += (arr[i] - rcurbest);
				rcur--;
			} else {
				curc += (arr[i] - rcurbest) * (rcur -1);
				rcur--;
				rcurbest = arr[i];
			}
		}
		minc = min(minc, curc);
	}
	cout<<minc<<"\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}