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
int calc(string &s) {
	int played = 0;
	int s1 = 0;
	int s2 =0;
	int rem1 = 5;
	int rem2 = 5;
	REP(i, 10) {
		played++;
		if (s[i]=='1') {
			if (i%2==0) {
				s1++;
			} else {
				s2++;
			}
		}
		if (i%2==0) {
			rem1--;
		} else {
			rem2--;
		}
		if (s1 + rem1 < s2||s2+rem2<s1) {
			break;
		}
	}return played;
}
void solve() {
	string s;
	cin>>s;
	string s1 = s;
	string s2 = s;
	REP(i, 10) {
		if (s[i]=='?') {
			if (i%2==0) {
				s1[i] = '0';
				s2[i] = '1';
			} else {
				s1[i] = '1';
				s2[i] = '0';
			}
		}
	}
	cout<<min(calc(s1), calc(s2))<<"\n";
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