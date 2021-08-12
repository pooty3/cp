#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
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
	string str1;
	string str2;
	cin>>str1>>str2;
	int j=0;
	REP(i, min(str2.length(), str1.length())) {
		if (str1[i]==str2[i]) {
			j++;
		} else {
			break;
		}
	}
	int u = 0;
	for (int i= 0; j+i < min(str2.length(), str1.length());i++){
		if (str2[str2.length()-1-i]==str1[str1.length()-1-i]) {
			u++;
		} else {
			break;
		}
	}
	cout<<(str2.length()-u-j);

}