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
char con = 'B';
char vow = 'A';
char act = 'L';
vector<char> vowels = {'A','E','I','O','U'};
bool passable(string &str) {
	int v=0;
	int con = 0;
	bool able = false;
	REP(i, str.length()) {
		if (str[i]=='_') continue;
		if (str[i]==act) {
			able = true;
		} 
		if (find(vowels.begin(), vowels.end(), str[i])!=vowels.end()) {
			v ++;
			con =0;
		} else {
			v=0;
			con++;
		}
		if (max(con,v)>=3) return false;

	}return able;

}
ll ways(string &str) {
	auto it = str.find('_');
	if (it==string::npos) {
		if (!passable(str)) {return 0;} 
		else {
		return 1;}
	} else {
		ll tot=0;
		string ori = str;
		ori[it] = act;
		tot += ways(ori);
		ori[it] = vow;
		tot += 5*ways(ori);
		ori[it] = con;
		tot += 20*ways(ori);
		return tot;

	}

}

int main()
{
	string str;
	cin>>str;
	cout<<ways(str);

}