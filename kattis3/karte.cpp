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
	vector<set<int>> ss(4, set<int>());
	string str;
	cin>>str;
	REP(i, str.size()/3) {
		int val = stoi(str.substr(i*3+1, 2));
		char c = str[i*3];
		int j;
		if (c=='P') j =0;
		if (c=='K') j =1;
		if (c=='H') j =2;
		if (c=='T') j =3;
		if (ss[j].find(val)!= ss[j].end()) {
			cout<<"GRESKA";return 0;
		}
		ss[j].insert(val);
	}
	REP(i, 4) {
		cout<<13 - ss[i].size()<<" ";
	}

}