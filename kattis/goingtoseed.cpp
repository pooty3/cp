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
	int low = 1;
	int high = n;
	int x1,x2;
	while (true) {
		if (low==high) {
			printf("A %d\n", low);
			fflush(stdout);
			break;
		} else {
			int tot = high-low +1;
			int seg = tot/4;
			vi segs(3, seg);
			REP(i, tot%4) {
				segs[i]++;
			}
			int e1 = low + segs[0]-1;
			int s2 = e1+1;
			int e2 = s2 + segs[1] - 1;
			int s3 = e2+1;
			int e3 = s3 + segs[2] -1;
			int s4 = e3+1;
			printf("Q %d %d %d %d\n", low, e2, s2, e3);
			fflush(stdout);
			cin>>x1>>x2;
			if (x1==1&&x2==1) {
				high = e2;
				low = s2;
			} else if (x1==1) {
				high = e1;
			} else if (x2==1) {
				high = e3;
				low = s3;
			} else {
				low = s4;
			}
            if (high!=low) {
              low--;
                low = max(low, 1);
                high++;
                high = min(high, n);  
            }
		}
	}


}