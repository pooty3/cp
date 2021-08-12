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
	vi arr(n);
	int p2 = 32;
	REP(i, n) {
		cin>>arr[i];
		int curpw = 0;
		int x = arr[i];
		while (x%2 ==0) {
			x/=2;
			curpw++;
		}
		p2 =min(curpw, p2);
	}

	REP(i, n) {
		arr[i]>>=p2;
	}
	int sm =0; 
	REP(i, n) {
		sm += arr[i];
	}
	if (sm%2 == 1) {
		cout<<0;return 0;
	}
	bitset<200001> bs;
	bs[0] =1;
	REP(i, n) {
		bs |= (bs<<arr[i]);
	}
	if (bs[sm/2] == 1) {
		cout<<1<<"\n";
		REP(i, n) {
			if (arr[i]%2 ==1) {
				cout<<(i+1);
				break;
			}
		}
	} else {
		cout<<0;
	}
}
