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
	while (true) {
		done:
		int n,m;cin>>n>>m;
		if (n==0&&m==0) break;
		vi harr(n);
		vi karr(m);
		REP(i, n) {
			int x;
			cin>>x;
			harr.push_back(-x);
		}
		REP(i, m) {
			int x;
			cin>>x;
			karr.push_back(-x);
		}
		SORT(harr);SORT(karr);
		int cost =0;
		priority_queue<int> pq;
		int pt=0;
		REP(i, n) {
			REPL(j, pt, m) {
				if (karr[j]>harr[i])break;
				pt++;
				pq.push(karr[j]);
			}
			if (pq.empty()) {
				cout<<"Loowater is doomed!\n"; goto done; 
			}
			cost -= pq.top();pq.pop();
		}
		cout<<cost<<"\n";
	}

}