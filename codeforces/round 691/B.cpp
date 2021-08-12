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

int main()
{
	int n;
	cin>>n;
	int tot=0;
	REP(i, 1001) {
		REPL(j, 1, 1001) {
			int diff = abs(i-j);
			int min;
			if (diff%2==0) {
				min = max(i,j)*2;
			} else {
				min = max(i,j)*2-1;
			}
			if (min > n ) {
				continue;
			}
			if (diff%2==1) {
				if ((n-min)%2==0) {
					tot++;
				}
			}else {
				if ((n-min)%4==0) {
					tot++;
				}
			}

		}
	}
	cout<<(tot*4 + (n%4==0? 1 :0));

}