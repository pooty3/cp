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
	string str1, str2;cin>>str2>>str1;
	if (str1==str2) {
		cout<<"Yes";return 0;
	}
	if (str2.length()!= str1.length() && str2.length() != str1.length()+1) {
		cout<<"No"; return 0;
	}
	if (str2.substr(1)== str1 && isdigit(str2[0])) {
		cout<<"Yes"; return 0;
	}
	if (str2.substr(0, str1.length())==str1 && isdigit(str2[str2.length()-1])) {
		cout<<"Yes"; return 0;
	}
	string s3;
	for (char ch: str2) {
		if (islower(ch)) {
			s3 += toupper(ch);
		} else if (isupper(ch)) {
			s3 += tolower(ch);
		} else {
			s3 += ch;
		}
	}
	if (s3==str1) {
		cout<<"Yes";
	} else {
		cout<<"No";
	}
}