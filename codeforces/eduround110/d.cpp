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
	int k;
	cin>>k;
	string s;
	cin>>s;
	vi mp(1<<k);
	map<int, int> rmp;
	int cur = 1;
	int start = (1<<k);
	REP(i, k) {
		start -= (1<<i); 
		REP(j, (1<<i)) {
			mp[cur] = start+j-1;
			rmp.insert({start+j-1, cur});
			cur++;
		}
	}
	vi arr((1<<(k+1)), 1);
	for (int i = (1<<k)-1; i>=1; --i) {
		int l = i*2;
		int r = i*2+1;
		if (s[mp[i]]=='?') {
			arr[i] = arr[l]+arr[r];
		}
		if (s[mp[i]]=='0') {
			arr[i] = arr[l];
		}
		if (s[mp[i]]=='1') {
			arr[i] = arr[r];
		}
	}
	int q;
	cin>>q;
	REP(zzz, q) {
		int n;
		char ch;
		cin>>n>>ch;n--;
		int i = rmp[n];
		s[n] = ch; 
		while (true) {
			int l = i*2;
			int r = i*2+1;
			if (s[mp[i]]=='?') {
				arr[i] = arr[l]+arr[r];
			}
			if (s[mp[i]]=='0') {
				arr[i] = arr[l];
			}
			if (s[mp[i]]=='1') {
				arr[i] = arr[r];
			}
			if (i==1) break;
			i /=2;
		}
		cout<<arr[1]<<"\n";
	}
}