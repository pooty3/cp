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
	cin>>n;
	vii arr;
	REP(i, n) {
		string s;
		cin>>s;
		REP(j, n) {
			if (s[j]  != '.') {
				arr.push_back({i,j});
			}
		}
	}
	int amt =0;
	int l = arr.size();
	REP(i, l) {
		REP(j, l) {
			if (i==j) continue;
			int dx = arr[i].first - arr[j].first;
			int dy = arr[i].second - arr[j].second; 
			REP(k,l) {
				if (j==k||i==k) continue;
				int dx1 = arr[i].first - arr[k].first;
				int dy2 = arr[i].second - arr[k].second; 
				amt += (dx1*dy == dy2*dx);
			}
		}
	}cout<<amt/6;
}