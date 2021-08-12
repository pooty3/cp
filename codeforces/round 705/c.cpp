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
	int n,k;
	cin>>n>>k;
	string str;
	cin>>str;
	if (n%k != 0) {
		cout<<-1<<"\n";
		return;
	}
	vi pre(26,0);
	REP(i, n) {
		pre[str[i]-'a']++;
	}
	int sum =0;
	REP(i, 26) {
		int z = pre[i]%k;
		if (z!=0) {
			sum += k-z;
		}
	}
	if (sum==0) {
		cout<<str<<"\n";
		return;
	}
	int prelen;
	REP(i, n) {
		int u = str[n-1-i] - 'a';
		pre[u]--;
		sum++;
		if (pre[u]%k ==0) {
			sum -= k;
		}
		REPL(j, u+1, 26) {
			pre[j]++;
			sum--;
			if (pre[j]%k == 1) {
				sum += k;
			}
			if (sum <= i) {
				char ch = 'a' + j;
				str[n-1-i] = ch;
				prelen = n-i;
				goto done;
			}
			pre[j]--;
			sum++;
			if (pre[j]%k ==0) {
			sum -= k;
			}
		}
	}
	done:
	multiset<int> s;
	REP(i, 26) {
		int z = pre[i]%k;
		if (z==0) continue;
		REP(j, k-z) {
			s.insert(i);
		}
	}
	REPL(i, prelen, n) {
		str[i] = 'a';
	}

	int l = s.size();
	int st = n-l;
	FOREACH(it, s) {
		char ch = (*it) + 'a';
		str[st] = ch;
		st++;
	}
	cout<<str<<"\n";
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