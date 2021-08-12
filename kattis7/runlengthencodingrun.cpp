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
	string s1,s2;cin>>s1>>s2;
	if (s1=="E") {
		char prev = s2[0];
		int count =1;
		REPL(i, 1, s2.length()) {
			if (s2[i]== prev) {
				count++;
			} else {
				cout<<prev<<count;
				prev = s2[i];
				count = 1;
			}
		}
		cout<<prev<<count;
	} else {
		REP(i, s2.length()) {
			REP(j, s2[i+1]-'0') {
				cout<<s2[i];
			}i++;
		}
	}
}