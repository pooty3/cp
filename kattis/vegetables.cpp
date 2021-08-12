#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
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

struct da{
	double val;
	double w;
	int p;
	bool operator<(const da& other) const{
		return this->val < other.val;
	}
};

int main()
{
	double t;
	int n;
	cin>>t>>n;
	priority_queue<da> pq;
	double mi=INF;
	REP(i, n) {
		double d;
		cin>>d;
		mi = min(d, mi);
		pq.push({d,d,1});
	}
	int chops = 0;
	while (true) {
		da d = pq.top();
		if (d.val*t < mi) {
			break;
		}
		chops++;
		pq.pop();
		d.p++;
		d.val = d.w/d.p;
		mi = min(d.val,mi);
		pq.push(d);
	}
	cout<<chops;


}