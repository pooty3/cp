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
	string w,p;
	cin>>w>>p;
	set<char> s;
	REP(i, w.size()) {
		s.insert(w[i]);
	}
	int co = 0;
	REP(i, 26) {
		auto it = s.find(p[i]);
		if (it == s.end()) {
			co++;
		}else {
			s.erase(it);
		}
		if (s.size()==0) {
			cout<<"WIN\n";break;
		} if (co == 10) {
			cout<<"LOSE\n";break;
		}
	}

}