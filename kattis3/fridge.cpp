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
	string str;cin>>str;
	vi arr(10, 0);
	for (char c : str) {
		arr[c-'0']++;
	}
	ii cur = {INF, 10};
	REPL(i, 1,10) {
		cur = min(cur, {arr[i], i});
	}
	cur = min(cur, {arr[0],10});
	auto [c, i] = cur;
	if (i == 10) {
		cout<<1;
		REP(z, c+1) {
			cout<<0;
		}
	} else {
		REP(z, c+1) {
			cout<<i;
		}
	}
}