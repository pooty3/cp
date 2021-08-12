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
int n;
void printcol(int i, int ind, vii& bucket) {
	int r = bucket[ind].first;
	int c = bucket[ind].second;
	cout<<i<<" "<<r<<" "<<c<<endl;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	int nexteven =0;
	int nextodd = 0;
	int tot = n*n;
	int evenno = tot/2;
	int oddno = tot/2;
	if (tot%2 == 1) {
		evenno++;
	}
	vii odds, evens;
	REP(i, n) {
		REP(j, n) {
			int offset = i%2==0?0:1;
			if ((j+offset)%2==0) {
				evens.push_back({i+1,j+1});
			} else {
				odds.push_back({i+1,j+1});
			}
		}
	}
	int i;
	cin>>i;
	int forb = i;
	int evencol = i%3+1;
	int oddcol = (i+1)%3+1;
	printcol(evencol, nexteven, evens);
	nexteven ++;
	REP(zz, n*n-1) {
		cin>>i;
		if (i==forb) {
			if (nexteven < evenno) {
				printcol(evencol, nexteven, evens);
				nexteven++;
			} else {
				printcol(oddcol, nextodd, odds);
				nextodd++;
			}
		}
		if (i == evencol) {
			if (nextodd < oddno) {
				printcol(oddcol, nextodd, odds);
				nextodd++;
			} else {
				printcol(forb, nexteven, evens);
				nexteven++;
			}
		}
		if (i==oddcol) {
			if (nexteven < evenno) {
				printcol(evencol, nexteven, evens);
				nexteven++;
			} else {
				printcol(forb, nextodd, odds);
				nextodd ++;
			}
		}
	}


}