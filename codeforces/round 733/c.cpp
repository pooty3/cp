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
	int n;
	cin>>n;
	vi aarr(n);
	vi barr(n);
	REP(i, n) {
		cin>>aarr[i];
	}
	REP(i, n) {
		cin>>barr[i];
	}
	int mx = n*2;
	int mn = 0;
	while (mn< mx) {
		vi aa = aarr;
		vi bb = barr;
		int md = (mx+mn)/2;
		REP(i, md) {
			aa.push_back(100);
			bb.push_back(0);
		}
		SORT(aa);
		SORT(bb);
		int needed = 0;
		REP(i, n+md) {
			if (i>= (n+md)/4) {
				needed += bb[i];
				needed -= aa[i];
			}
		}
		if (needed<=0) {
			mx = md;
		} else {
			mn = md+1;
		}
	} cout<<mn<<"\n";

	/*SORT(barr);
	SORT(aarr);
	priority_queue<int> pq;
	priority_queue<int> pq2;
	int curneeded =0;
	REP(i, n) {
		if (i >= n/4) {
			curneeded += barr[i];
			curneeded -= aarr[i];
			pq.push(-aarr[i]);
		} else {
			pq2.push(barr[i]);
		}
	}
	int cur =0;
	while (true) {
		if (curneeded <=0 ) break;
		cur++;
		curneeded -=100;
		pq.push(-100);
		if ((n+cur)%4==0) {
			curneeded += pq.top();
			pq.pop();
		}
		pq2.push(0);
		curneeded += pq2.top();
		pq2.pop();
	}cout<<cur<<"\n";*/
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