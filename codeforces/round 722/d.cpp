#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999999999999
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
	int n,m;
	cin>>n>>m;
	vvll adj(n, vll(n, INF));
	vector<vii> arr(n, vii());
	REP(i, m) {
		int a,b;ll c;
		cin>>a>>b>>c;
		//a = i; b = (i+1)%n;c=1;
		arr[a].push_back({b,c});
	}
	REP(i, n) {
		for (auto [b, t]: arr[i]) {
			REP(j, n) {
				adj[i][(b+j)%n] = min(adj[i][(b+j)%n], (ll)t+j);
			}
		}
	}
	REP(i,n) {
		vll dist(n, INF);
		dist[i] = 0;
		bool marked[n];
		memset(marked, 0, sizeof(marked));
		REP(ttt, n) {
			ll curmn = INF;
			int curidx = -1;
			REP(z, n) {
				if(!marked[z] && dist[z]<curmn) {
					curmn = dist[z];
					curidx = z;
				}
			}
			marked[curidx] = true;
			ll offset = dist[curidx]%n;
			REP(j, n) {
				dist[j] = min(dist[j], dist[curidx] + adj[curidx][(j-offset+n)%n]); 
			}
		}
		REP(j, n) {
			cout<<dist[j]<<" ";
		}cout<<"\n";
	}
}