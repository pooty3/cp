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

bool able(int mw, vi &arr, int k) {
	int cur=0;
	int curw =0;
	for (int i: arr) {
		if (i > mw) return false;
		if (curw + i > mw){
			cur++;
			curw = 0;
		}
		curw += i;
	}
	return cur < k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,k;cin>>n>>k;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	int hgh = 1e9;
	int lw =1;
	while (lw < hgh) {
		int md = (hgh+lw)/2;
		if (able(md, arr, k)) {
			hgh = md;
		} else {
			lw = md+1;
		}
	}
	cout<<lw;

}