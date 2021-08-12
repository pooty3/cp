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
	int n,e;cin>>n>>e;
	vector<set<int>> arr(n);
	int song = 0;
	REP(zz, e) {
		int t;
		cin>>t;
		vi z;
		bool bard = false;
		REP(j, t) {
			int x;
			cin>>x;x--;
			if (x==0) bard = true;
			else {
				z.push_back(x);
			}
		}
		if (bard) {
			for (auto i: z) {
				arr[i].insert(song);
			}
			song++;
		} else {
			set<int> songs;
			for (auto i: z) {
				for (auto j: arr[i]) {
					songs.insert(j);
				}
			}
			for (auto i:z) {
				arr[i].insert(songs.begin(), songs.end());
			}
		}
	}
	int count =1;
	set<int> ss = {1};
	REP(i, n) {
		if (arr[i].size() == song) {
			ss.insert(i+1);
		}
	}
	for (auto i: ss) {
		cout<<i<<"\n";
	}
}