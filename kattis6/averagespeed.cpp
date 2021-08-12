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
	int cur =0;
	int curt =0;
	int curspeed=0;
	string str;
	while(getline(cin, str)) {
		stringstream ss(str);
		string t;
		ss>>t;
		int h,m,s;
		sscanf(t.c_str(), "%d:%d:%d", &h, &m, &s);
		int tt = h*3600 + m*60 + s;
		cur += curspeed*(tt-curt);
		curt = tt;
		int ns;
		if(ss>>ns) {
			curspeed = ns;
		} else {
			printf("%s %.2f km\n", t.c_str(), (ld)cur/3600);
		}
	}

}