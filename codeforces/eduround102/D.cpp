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

void solve() {
	int n,m;
	cin>>n>>m;
	string str;
	cin>>str;
	vi arr(n+1);
	arr[0] = 0;
	REPL(i,1,n+1) {
		arr[i] = arr[i-1];
		if (str[i-1]=='+') {
			arr[i]++;
		} else {
			arr[i]--;
		}
	}
	vi curh1(n+1), curl1(n+1);
	vi curh2(n+1),curl2(n+1);
	int ch=-INF, cl = INF;
	REP(i, n+1) {
		ch = max(ch, arr[i]);
		curh1[i] = ch;
		cl = min(cl, arr[i]);
		curl1[i] = cl;
	}
	ch = -INF, cl= INF;
	REP(i, n+1) {
		ch = max(ch, arr[n-i]);
		cl = min(cl, arr[n-i]);
		curh2[i] = ch;
		curl2[i] = cl;
	}
	REP(i, m) {
		int l,r;
		cin>>l>>r;
		int ch = curh1[l-1];
		int cl = curl1[l-1];
		int shift = arr[r]- arr[l-1];
		int ch2 = curh2[n-r] - shift;
		int cl2 = curl2[n-r] - shift;
		ch = max(ch, ch2);
		cl = min(cl, cl2);
		cout<<(ch-cl+1)<<"\n";
	}

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