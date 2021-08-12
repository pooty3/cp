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

struct story {
	int w,h,x,y;
};
vector<story> arr;

bool inside(int x1,int y1, int x2, int y2) {
	return !(y1 <= x2||x1>=y2);
}
bool checkoverlap(int mask, int ind) {
	story &c = arr[ind];
	REP(i, ind) {
		if(mask&(1<<i)) {
			story& ch = arr[i];
			if (inside(c.x, c.x+c.w, ch.x, ch.x + ch.w) && inside(c.y, c.y+c.h, ch.y, ch.y + ch.h)) { 
				return true;
			}
		}
	}
	return false;

}

int maxarea(int mask, int ind, int cursize) {
	if (ind == arr.size()) {
		return cursize;
	} else {
		int area1 = maxarea(mask, ind+1, cursize);
		if (!checkoverlap(mask, ind)) {
			int area2= maxarea(mask|(1<<ind), ind+1, cursize + arr[ind].w * arr[ind].h);
			area1 = max(area1, area2);

		} 
		return area1;

	}

}
int main()
{
	while (true) {
		int n;
		cin>>n;
		if (n==0) break;
		arr.clear();
		REP(i, n) {
			int w,h,x,y;
			cin>>w>>h>>x>>y;
			arr.push_back({w,h,x,y});


		}
		cout<<maxarea(0,0,0)<<"\n";

	}

}