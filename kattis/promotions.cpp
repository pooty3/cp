#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999
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
	int a,b,e,p;
	cin>>a>>b>>e>>p;
	vvi adj(e, vi());
	vvi iadj(e, vi());
	vi in(e,0);
	vi out(e,0);
	REP(i, p) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		out[u]++;
		iadj[v].push_back(u);
		in[v]++;
	}
	vi marr(e, -1);
	vi miarr(e, -1);
	REP(i, e) {
		stack<int> s;
		REP(j, e) {
			if (in[j]==0) {
				s.push(j);
			}
		}
		vi intemp = in;
		int tot=0;
		while (!s.empty()) {
			int u = s.top();
			s.pop();
			if (u!=i) {
				tot++;
				FOREACH(it, adj[u]) {
					intemp[*it]--;
					if (intemp[*it]==0) {
						s.push(*it);
					}
				}
			}
		}
		marr[i] = tot+1;
		REP(j, e) {
			if (out[j]==0) {
				s.push(j);
			}
		}
		vi outemp = out;
		tot =0;
		while (!s.empty()) {
			int u = s.top();
			s.pop();
			if (u!=i) {
				tot++;
				FOREACH(it, iadj[u]) {
					outemp[*it]--;
					if (outemp[*it]==0) {
						s.push(*it);
					}
				}
			}
		}
		miarr[i] = tot+1;
	}
	int totA=0;
	int totB=0;
	int totC=0;
	REP(i, e) {
		if (marr[i]<= a) totA++;
		if (marr[i]<=b) totB++;
		if (miarr[i]<=e-b) totC++;
	}
	cout<<totA<<"\n";
	cout<<totB<<"\n";
	cout<<totC<<"\n";


}