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

unordered_map<string, int>mp;
vvi adj(11000, vi());
vi vit(11000, 0);
vi parent(11000, -1);

bool cycle(int i) {
	vit[i] = 1;
	FOREACH(it, adj[i]) {
		if (vit[*it]==0) {
			parent[*it] = i;
			if (cycle(*it)) {
				return true;
			}
		}
		if (vit[*it]==1) {
			if (parent[*it]!=i) {
				return true;
			}
		}
	}
	vit[i] =2;

	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	int c=0;
	REP(i, n) {
		string s1, s2;
		cin>>s1>>s2;
		if (mp.find(s1)==mp.end()) {
			mp.insert({s1, c}); c++;
		}
		if (mp.find(s2)==mp.end()) {
			mp.insert({s2, c}); c++;
		}
		adj[mp[s1]].push_back(mp[s2]);
	}
	string s1;
	while(cin>>s1) {
		vit.assign(11000, 0);
		parent.assign(11000, -1);
		cout<<s1<<" ";
		if (cycle(mp[s1])) {
			cout<<"safe";
		} else {
			cout<<"trapped";
		}cout<<"\n";
	}

}