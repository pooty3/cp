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
	string a = "ABC";
	string b =  "BABC";
	string c = "CCAABB";
	string str;
	cin>>str;
	vi arr(3,0);
	REP(i, n) {
		if (str[i] == a[i%3]) arr[0]++;
		if (str[i] == b[i%4]) arr[1]++;
		if (str[i] == c[i%6]) arr[2]++;
	}
	int mx = max(max(arr[0], arr[1]),arr[2]);
	cout<<mx<<"\n";
	if (arr[0]== mx) cout<<"Adrian\n";
	if (arr[1]==mx) cout<<"Bruno\n";
	if (arr[2] == mx) cout<<"Goran\n";
}