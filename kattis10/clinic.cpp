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
	int n;
	ll k;cin>>n>>k;
	set<pair<ll, string>> pq;
	set<string> inclinic;
	REP(i, n) {
		int q;
		cin>>q;
		if (q==1) {
			ll t,s;string m;
			cin>>t>>m>>s;
			ll sev = s - t*k;
			pq.insert({-sev, m});
			inclinic.insert(m);
		} else if (q==2) {
			int tt;cin>>tt;
			bool found = false;
			while (!pq.empty()) {
				auto [val, nm] = *pq.begin();pq.erase(pq.begin());
				if(inclinic.find(nm)!=inclinic.end()) {
					cout<<nm<<"\n"; 
					found = true;
					inclinic.erase(nm);
					break;
				}
			}
			if (!found) {
				cout<<"doctor takes a break\n";
			}
		} else {
			string nm;cin>>nm;
			if (inclinic.find(nm)!= inclinic.end()) {
				inclinic.erase(nm);
			}
		}
	}
}