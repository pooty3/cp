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
ll md = 31607;
int modPow(int b, int p) {
	if (p==0) return 1;
	if (p%2==1) {
		return (b*modPow(b, p-1))%md;
	} else {
		int res = modPow(b, p/2);
		return (res*res)%md;
	}
}
int modInv(int b) {
	return modPow(b, md-2);
}
int minss(int x, int y) {
	return (x-y+md)%md;
}
int minusFromOne(int v) {
	return minss(1, v);
}
int n;
vvi prob;
vvi arr;
vvi conprob;
int recurse(int cur, int BS) {
	if (cur == n+2) {
		int basebitset = BS/4;
		int fval = 1;
		int bb = (1<<n)-1;
		bool t1 = BS&1;
		bool t2 = BS&2;
		REP(i, n) {
			int bset = basebitset;
			if (t1) {
				bset |= (1<<i);
			}
			if (t2) {
				bset |= (1<<(n-1-i));
			}
			fval *= prob[i][bb-bset];
			fval %= md;
		}
		return fval;
	}
	int v1 = recurse(cur+1, BS);
	int v2 = recurse(cur+1, BS|(1<<cur));
	int pval;
	if (cur == 0) {
		int fval = 1;
		REP(i, n) {
			fval *= arr[i][i];
			fval %= md;
		}
		pval = fval;
	} else if (cur == 1) {
		int fval = 1;
		REP(i, n) {
			int j = n-1-i;
			if (i==j) {
				if (BS&1) continue;
			}
			fval *= arr[i][j];
			fval %= md;
		}
		pval = fval;
	} else {
		pval = conprob[cur-2][BS&3];
	}
	return minss(v1, (v2*pval)%md);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	arr.assign(n,vi(n));
	int cccc = modInv(10000);
	REP(i,n) {
		REP(j, n) {
			int x;
			cin>>x;
			arr[i][j] = (x*cccc)%md;
		}
	}
	prob.assign(n, vi(1<<n));
	conprob.assign(n, vi(4));
	REP(i, n) {
		prob[i][0] = 1;
		REPL(j,1, (1<<n)) {
			int pow2 = LSOne(j);
			prob[i][j] = (prob[i][j-pow2] * arr[i][__builtin_ctz(pow2)])%md;
		}
	}
	REP(i, n) {
		REP(j, (1<<n)) {
			prob[i][j] = minusFromOne(prob[i][j]);
		}
	}
	REP(j, n) {
		REP(bs,4) {
			int fval = 1;
			REP(i, n) {
				if (i==j) {
					if (bs&1) continue;
				}
				if (i+j == n-1) {
					if (bs&2) continue;
				}
				fval *= arr[i][j];
				fval %= md;
			}
			conprob[j][bs] = fval;
		}
	}
	cout<<minusFromOne(recurse(0,0));
}	