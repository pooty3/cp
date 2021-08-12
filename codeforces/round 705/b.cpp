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

vi arr = {0,1, 5, -1, -1, 2,-1,-1,8,-1};
ii reflect(ii &p) {
	auto [h,m] = p;
	int nm = -1, nh = -1;
	if (arr[h/10] != -1 && arr[h%10] != -1) {
		nm = arr[h%10] * 10 + arr[h/10];
	}
	if (arr[m/10] != -1 && arr[m%10] != -1) {
		nh = arr[m%10] * 10 + arr[m/10];
	}
	return {nh,nm};
}

void solve() {
	int h,m;
	cin>>h>>m;
	string str;
	cin>>str;
	int curh = stoi(str.substr(0,2));
	int curm = stoi(str.substr(3));
	int cur = curh* m + curm;
	while (true) {
		cur %= (h*m);
		ii curp= {cur/m, cur%m};
		ii p = reflect(curp);
		if (p.second == -1 || p.first == -1) {
			cur++;
			continue;
		} 
		if (p.second < m && p.first< h) {
			break;
		}
		cur++;
	}
	printf("%02d:%02d\n", cur/m, cur%m);
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}
}