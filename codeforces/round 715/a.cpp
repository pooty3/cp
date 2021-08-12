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
int n;



void solve() {
	int n;
	cin>>n;
	n*=2;
	vector<string> sarr(3);
	REP(i, 3) {
		cin>>sarr[i];
	}
	vi pointers(3,0);
	int done=-1;
	string res="";
	while (true) {
		set<int> s0;
		set<int> s1;
		REP(i, 3) {
			if (sarr[i][pointers[i]] == '0') {
				s0.insert(i);
			} else {
				s1.insert(i);
			}
		}
		if (s0.size() > s1.size()) {
			res += '0';
			for (int i: s0) {
				pointers[i]++;
			}
		} else {
			res += '1';
			for (int i: s1) {
				pointers[i]++;
			}
		}
		REP(i, 3) {
			if (pointers[i]==n) {
				done = i; break;
			}
		}
		if (done != -1) {
			break;
		}
	}
	//cout<<res;
	set<int> mp;
	REP(i, 3) {
		if (done != i) {
			mp.insert(i);
		}
	}
	int curmn = INF;
	int rem = -1;
	for (int i: mp) {
		int left = n- pointers[i];
		if (left < curmn) {
			curmn = left;
			rem = i;
		} 
	}
	REPL(j, pointers[rem], n) {
		res += sarr[rem][j];
	}
	cout<<res<<"\n";
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