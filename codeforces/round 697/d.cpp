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
	vi pr(n);
	priority_queue<int> pq1,pq2;
	REP(i, n) {
		cin>>pr[i];
	}
	REP(i, n) {
		int x;
		cin>>x;
		if (x == 2) {
			pq2.push(pr[i]);
		} else {
			pq1.push(pr[i]);
		}
	}

	int needed = m;
	int con = 0;
	while (!pq1.empty()|| !pq2.empty()) {
		if (needed <=0 ) break;
		if (!pq1.empty()&&pq1.top() >= needed) {
			con++;
			needed -=pq1.top();
			break;
		} else if (pq1.size()<=1) {
			if (!pq2.empty()) {
				con+=2;
				needed -= pq2.top();
				pq2.pop();
			} else {
				needed -= pq1.top();
				con++;
				pq1.pop();
			}
		} else {
			int temp = pq1.top();
			pq1.pop();
			int val1 = pq1.top() + temp;
			if (!pq2.empty()&&val1 < pq2.top()){
				needed -= pq2.top();
				con += 2;
				pq2.pop();
				pq1.push(temp);
			} else {
				needed-= temp;
				con++;
			}
		}
	}
	if (needed >0 ) {
		cout<<-1<<"\n";
	} else {
		cout<<con<<"\n";
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