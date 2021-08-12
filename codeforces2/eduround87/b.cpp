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
bool able(vi &arr) {
	REP(i, 3) {
		if (arr[i]==0) return false;
	}return true;
}
void solve() {
	string s;
	cin>>s;
	int n = s.size();
	int curl = 0;
	int curr = -1;
	vi arr(3,0);
	REP(i, n) {
		arr[s[i]-'1']++;
		if (able(arr)) {
			curr = i;

			break;
		}
	}
	if (curr==-1) {
		cout<<0<<"\n"; return;
	}
	int curlen = curr+1;
	while (true) {
		if (able(arr)) {
			curlen = min(curlen, curr-curl+1);
			arr[s[curl]-'1']--;
			curl++;
		} else {
			curr++;
			if (curr == n) break;
			arr[s[curr]-'1']++;
		}
	}
	cout<<curlen<<"\n";

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