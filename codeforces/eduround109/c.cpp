#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 1e9
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
vi res;
void dosolve(map<int,int> &mp, vii &arr,int m) {
	stack<int> st;
	vi curL;
	for (auto [x, dir]: arr) {
		if (dir == 1) {
			st.push(x);
		} else {
			if (st.empty()) {
				curL.push_back(x);
			} else {
				int v = st.top();st.pop();
				res[mp[v]] = abs(x-v)/2;
				res[mp[x]] = abs(x-v)/2;
			}
		}
	}
	vi curR;
	while (!st.empty()) {
		int i = st.top(); st.pop();
		curR.push_back(i);
	}
	int finalL=-1;
	int finalR = -1;
	REP(i, curL.size()) {
		if (i+1==curL.size()) {
			finalL = curL[i];
			continue;
		}
		int dist = curL[i] + curL[i+1];
		dist/=2;
		res[mp[curL[i]]] = dist;
		res[mp[curL[i+1]]] = dist;
		++i;
	}
	REP(i, curR.size()) {
		if (i+1==curR.size()) {
			finalR = curR[i];
			continue;
		}
		int dist = 2*m - curR[i] - curR[i+1];
		dist/=2;
		res[mp[curR[i]]] = dist;
		res[mp[curR[i+1]]] = dist;
		++i;
	}
	if (finalR != -1 && finalL != -1) {
		int dist = m+(m-finalR) + finalL;
		dist /=2;
		res[mp[finalR]] = dist;
		res[mp[finalL]] = dist;
	}

}

void solve() {
	int n,m;
	cin>>n>>m;
	vi rarr(n);
	vector<char> dir(n);
	map<int,int> mp;
	REP(i, n) {
		cin>>rarr[i];
		mp[rarr[i]] = i;
	}
	REP(i,n) {
		cin>>dir[i];
	}
	res.assign(n, -1);
	vii evens;
	vii odds;
	REP(i, n) {
		if (rarr[i]%2==0) {
			evens.push_back({rarr[i], dir[i]=='R'});
		} else {
			odds.push_back({rarr[i], dir[i]=='R'});
		}
	}
	SORT(evens);
	SORT(odds);
	dosolve(mp, evens,m);
	dosolve(mp, odds,m);
	for (auto i: res) {
		cout<<i<<" ";
	}cout<<"\n";
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}