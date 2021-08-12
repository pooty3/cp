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
set<int> npossibleletter(vvi &arr, int n, int m, int ni, int mi) {
	set<int> impossible;
	vi ndir= {0,0,-1,1};
	vi mdir = {-1,1,0,0};
	REP(i, 4) {
		int nii = ni+ndir[i];
		int mii = mi+mdir[i];
		if(nii<n && nii>=0&& mii<m &&mii>=0) {
			impossible.insert(arr[nii][mii]);
		}
	}
	return impossible;
}
int findmn(set<int> &s1, set<int> &s2) {
	REP(i, 26) {
		if (s1.find(i)==s1.end() && s2.find(i)==s2.end()) {
			return i;
		}
	} 

	return 0;
}
void solve() {
	int n,m,k;cin>>n>>m>>k;
	bool toflip = false;
	if (n%2!=0) {
		int temp = n;
		n = m;
		m = temp;
		k = n*m/2 - k;
		toflip = true;
	}
	if (k%2!=0) {
		cout<<"NO\n";return;
	}
	if ((n/2) * (m/2) * 2<k) {
		cout<<"NO\n";return;
	}cout<<"YES\n";
	vvi arr(n, vi(m,-1));
	int curn = 0;
	int curm = 0;
	REP(i, k) {
		set<int> s1 = npossibleletter(arr, n, m, curn, curm);
		set<int> s2 = npossibleletter(arr, n, m, curn, curm+1);
		int val = findmn(s1, s2);
		arr[curn][curm] = val;
		arr[curn][curm+1] = val;
		curn++;
		if (curn == n) {
			curn =0;
			curm+=2;
		}
	}
	bool end = false;
	REP(i, (n*m)/2-k) {
		set<int> s1 = npossibleletter(arr, n, m, curn, curm);
		set<int> s2 = npossibleletter(arr, n, m, curn+1, curm);
		int val = findmn(s1, s2);
		arr[curn][curm] = val;
		arr[curn+1][curm] = val;
		if (end) {
			curn+=2;
		} else {
			if (i%2==1) {
				curn+= 2;
				curm--;
				if (curn == n) {
					curn = 0;
					curm+=2;
				}
			} else {
				curm++;
				if (curm==m) {
					end = true;
					curm--;
					curn+=2;
				}
			}
		}
	}
	vvi fans = arr;
	if (toflip) {
		vvi farr(m, vi(n));
		REP(i, m) {
			REP(j,n) {
				farr[i][j] = arr[j][i];
			}
		}
		fans = farr;
	}
	for (auto vv: fans) {
		for (auto i: vv) {
			cout<<(char)('a'+i);
		}cout<<"\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}