#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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

int main()
{
	vi arr(3);
	string str;
	cin>>str;
	REP(i, str.length()) {
		arr[str[i]=='T'? 0 : str[i]=='C'? 1 : 2]++;


	}
	int m= min(arr[0], min(arr[1], arr[2]));
	int s = m*7;
	REP(i, 3) {
		s += arr[i]*arr[i];

	}
	cout<<s;


}