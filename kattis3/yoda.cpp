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
	string s1,s2;
	cin>>s1>>s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	string f1,f2;
	REP(i, max(s1.length(), s2.length())) {
		int t1 = i<s1.length()?s1[i] -'0':-1;
		int t2 = i<s2.length()?s2[i]-'0':-1;
		if (t1>=t2) {
			f1 = s1[i] + f1;
		} 
		if (t2>=t1) {
			f2= s2[i] + f2;
		}
	}
	if (f1 == "") {
		cout<<"YODA\n";
	} else {
		cout<<stoi(f1)<<"\n";
	}
	if (f2 == "") {
		cout<<"YODA\n";
	} else {
		cout<<stoi(f2)<<"\n";
	}
}