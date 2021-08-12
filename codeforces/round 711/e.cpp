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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	multimap<int, ii> mp;
	REP(i, n) {
		REPL(j,i+1, n) {
			if (i == j) continue;
			int d = arr[i]- arr[j];
			mp.insert({-abs(d), {i, j}});
		}
	}
	for (auto &[d,p] : mp) {
		 auto &[x,y]  = p;
		 y++;x++;
		 if (arr[x-1] > arr[y-1]) {
		 	cout<<"? "<<x<<" "<<y<<endl;
		 } else{
		 	cout<<"? "<<y<<" "<<x<<endl;
		 }
		 string str;
		 cin>>str;
		 if (str[0] == 'Y') {
		 	cout<<"! "<<y<<" "<<x<<endl;
		 	return 0;
		 }
	}
	cout<<"! 0 0"<<endl;

}