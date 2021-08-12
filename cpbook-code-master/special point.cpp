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
struct point {
	ll x,y;
};
struct point_frac {
	ll x,y;
	ll frac;
};
struct line {
	ll a,b,c;
};
void pointsToLine(const point &p1, const point p2, line &l) {
	if (p1.x == p2.x) {
		l = {1,0,-p1.x};
	} else {
		ll a = p2.y-p1.y;
		ll b = p1.x - p2.x;
		ll c = a*p1.x + b*p1.y;
		l = {a,b,-c};
	}
}
bool areParallel(line l1, line l2) {
	return l1.a*l2.b == l2.a*l1.b;
}
bool areIntersect(line l1, line l2, point_frac &p) {
	if (areParallel(l1,l2)) return false;
	ll det = l1.a*l2.b - l1.b*l2.a;
	ll x = -l1.c * l2.b +l2.c*l1.b;
	ll y = l2.a*l1.c - l2.c*l1.a;
	if (det < 0) {
		p = {-x,-y,-det};
	} else {
		p = {x,y,det};
	}
	return true;
}