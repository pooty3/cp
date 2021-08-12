#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
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

vi udir = {1,0};
vi vdir = {0,1};
int r,c;
void solve(int tss) {
	ll f,s;
	cin>>r>>c>>f>>s;
	vector<string> current(r);
	vector<string> wanted(r);
	REP(i, r) {
		cin>>current[i];
	}
	ll tot =0;
	set<ii> wrongs;
	REP(i,r) {
		cin>>wanted[i];
		REP(j, c) {
			if (current[i][j]!= wanted[i][j]) {
				wrongs.insert({i,j});
				tot += f;
			}
		}
	}
	vii cur;
	for (auto &[r,c]: wrongs) {
		cur.push_back({r,c});
	}
	ll curS = s;
	while(curS < 2*f) {
		vii nst;
		for (auto &[r,c]: cur) {
			if wrongs.find({r,c})!= wrongs.end()
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve(i+1);
	}

}