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



double pos(map<double,double> &arr, double t) {
	auto it = arr.lower_bound(t);
	if (it == arr.begin()) {
		return it->second;
	} else {
		auto it2 = prev(it);
		return it2->second + (it->second - it2->second)/(it->first - it2->first) * (t- it2->first);
	}
}

int main()
{
	int a,d;
	cin>>a>>d;
	map<double, double> aarr;
	map<double, double> darr;
	int curtime=0;
	double curpos = 0;
	aarr.insert({curtime, curpos});
	double offset = 0;
	REP(i, a) {
		int h,t;
		cin>>h>>t;
		curtime +=t;
		curpos +=h;
		if (h<0.5) {
			offset += 0.0000001;
		} else {
			offset = 0;
		}
		aarr.insert({curtime, curpos + offset});
	}
	double mx = curtime;
	curtime =0;
	darr.insert({curtime, curpos});
	offset =0;
	REP(i, d) {
		int h,t;
		cin>>h>>t;
		curtime+=t;
		curpos-=h;
		if (h<0.5) {
			offset += 0.0000001;
		} else {
			offset = 0;
		}
		darr.insert({curtime, curpos - offset});
	}
	double mn = 0;
	while (mx - mn > 0.00001) {
		double md = (mx+mn)/2;
		double d1 = pos(aarr, md);
		double d2 = pos(darr, md);
		if (d1==d2) {
			mn = md;
			mx = md;
			break;
		} else if(d1 < d2) {
			mn = md;
		} else {
			mx = md;
		}
	}
	//cout<<pos(darr,5);
	printf("%.8f", mn);

}