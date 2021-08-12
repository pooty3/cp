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
	int l = 1;
	int h = n;
	while (h-l > 1) {
		printf("? %d %d\n", l,h);
		 cout.flush();
		int x;
		cin>>x;
		int len = h-l+1;
		int hf = len%2==0? len/2 : len/2 +1;
		if (x <= l + hf-1) {
			printf("? %d %d\n", l,l+hf-1);
			 cout.flush();
			int x1;
			cin>>x1;
			if (x1 != x) {
				l = l+hf;
			} else {
				h = l+hf-1;
			}
		} else {
			printf("? %d %d\n", h-hf+1,h);
			 cout.flush();
			int x1;
			cin>>x1;
			if (x1!=x) {
				h = h-hf;
			} else {
				l = h-hf+1;
			}
		}
	}
	int ans;
	if (h-l ==1) {
		printf("? %d %d\n", l,h);
		 cout.flush();
		int x;
		cin>>x;
		if (x==l) {
			ans = h;
		} else {
			ans = l;
		}
	} else {
		ans = l;
	}
	printf("! %d\n", ans);
	cout.flush();
}