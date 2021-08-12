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
	string str;
	while (getline(cin, str)) {
		stringstream ss(str);
		vi arr;
		int mx = 0;
		int x;
		while (ss>>x) {
			mx= max(x,mx);
			arr.push_back(x);
		}
		bitset<2001> bs;
		bs.reset();
		bool ruler = true;
		for (auto i: arr) {
			for (auto j: arr) {
				if (i<=j) continue;
				if (bs[abs(i-j)]==1) {
					ruler = false;
				}
				bs[abs(i-j)] = 1;
			}
		}
		if (!ruler) {
			cout<<"not a ruler\n"; continue;
		}
		if (bs.count() == mx) {
			cout<<"perfect\n";
		} else {
			cout<<"missing";
			REPL(i, 1, mx+1) {
				if (bs[i]==0) {
					cout<<" "<<i;
				}
			}
			cout<<"\n";
		}
	}

}