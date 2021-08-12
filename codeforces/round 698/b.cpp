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

class SegmentTree{
public:
int n;
vi A, st, lazy;
int l(int p) {
	return p<<1;
}
int r(int p) {
	return (p<<1) +1;
}
int conquer(int a,int b) {
	if (a==-1) return b;
	if (b==-1) return a;
	return a+b;
}
void build(int p, int L, int R) {
	if (L==R) {
		st[p] = A[L];
	} else {
		int m = (L+R)/2;
		build(l(p), L,m);
		build(r(p), m+1, R);
		st[p] = conquer(st[l(p)], st[r(p)]);
	}
}
void propagate(int p, int L, int R) {
	if (lazy[p] != -1) {
		st[p] = lazy[p];
		if (L!=R) {
			lazy[l(p)] = lazy[r(p)] = lazy[p]/2;
		} else {
			A[L] = lazy[p];
 		}
 		lazy[p] = -1;
	}
}
int RMQ(int p, int L, int R, int i, int j) {
	propagate(p, L, R);
	if (i> j) return -1;
	if ((L>=i) && (R<=j)) return st[p];
	int m = (L+R)/2;
	return conquer(RMQ(l(p), L , m, i , min(m,j)),
		RMQ(r(p), m+1, R, max(i, m+1), j));
}
void update(int p, int L, int R, int i, int j, int val) {
	propagate(p,L,R);
	if (i>j) return;
	if ((L>=i)&&(R<=j)) {
		lazy[p] = val;
		propagate(p, L , R);
	} else {
	int val2 = val/(j-i+1);
	int m = (L+R)/2;
	int diff1 = min(m,j) -i + 1;
	int diff2 = j-max(i, m+1) +1;
	update(l(p), L, m, i , min(m, j), diff1* val2);
	update(r(p), m+1, R, max(i, m+1),j, diff2* val2);
	st[p] = st[l(p)] + st[r(p)];
	}
}
SegmentTree(int sz): n(sz), st(4*n), lazy(4*n, -1) {}
SegmentTree(const vi&initialA) : SegmentTree((int) initialA.size()) {
	A = initialA;
	build(1, 0, n-1);
}

void update(int i, int j, int val) {
	update(1,0,n-1, i,j,val);

}
int RMQ(int i, int j) {
	return RMQ(1,0,n-1, i, j);
}

};

void solve() {
	int n,q;
	cin>>n>>q;
	int arrsize =1;
	while (arrsize< n) {
		arrsize *=2;
	}
	vi sarr(arrsize, 0);
	vi earr(arrsize, 0);
	string s1,s2;
	cin>>s1>>s2;
	REP(i, n) {
		sarr[i] = s1[i] - '0';
	}
	REP(i, n) {
		earr[i] = s2[i] - '0';
	}
	SegmentTree st(earr);

	bool possible = true;
	vii p(q);
	REP(i, q) {
		int l,r;
		cin>>l>>r;l--;r--;
		p[i] = {l,r};
	}
	REP(i, q) {
		int l = p[q-1-i].first;
		int r = p[q-1-i].second;
		int v = st.RMQ(l,r);
		int diff = r-l+1;
		if (v*2 == diff) {
			possible = false;
			break;
		}
		if (v*2 > diff) {
			st.update(l,r, diff);
		} else {
			st.update(l,r,0);
		}

	}

	if (!possible) {
		cout<<"NO\n";
	} else {
		REP(i, n) {
			if(st.RMQ(i,i) != sarr[i]) {
				possible = false;
				 break;
			} 
		}
		if (!possible) {
			cout<<"NO\n";
		} else {
			cout<<"YES\n";
		}
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