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
	string str;cin>>str;
	char cur = str[0];
	int v =0;
	REPL(i,1, str.length()) {
		if (cur != str[i]) {
			v++;
		}
		if (str[i]=='D') {
			v++;
		}
		cur = 'U';
	}
	cout<<v<<"\n";
	cur = str[0];
	v =0;
	REPL(i,1, str.length()) {
		if (cur != str[i]) {
			v++;
		}
		if (str[i]=='U') {
			v++;
		}
		cur = 'D';
	}
	cout<<v<<"\n";
	cur = str[0];
	v =0;
	REPL(i,1, str.length()) {
		if (cur != str[i]) {
			v++;
		}
		cur = str[i];}
	cout<<v<<"\n";
}