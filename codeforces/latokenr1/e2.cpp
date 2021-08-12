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

int ask(vi &arr) {
	cout<<"? ";
	for (auto i: arr) {
		cout<<i<<" ";
	}cout<<endl;
	int x;cin>>x;
	return x;
}
void printres(int m) {
	cout<<"! "<<m<<endl;
}
int main()
{
	int n,k;
	cin>>n>>k;
	vi p(n+1, -1);
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		REP(i, k+1) {
			int neededlen = u+k-i;
			if (neededlen>n||neededlen<k) continue;
			int v = u+k-2*i;
			if (v<0||p[v]!=-1) continue;
			q.push(v);
			p[v] = u;
		}
	}
	if (p[n]==-1) {
		cout<<-1<<endl; return 0;
	}
	stack<int> route;
	int cur = n;
	while (cur!=0) {
		route.push(cur);
		cur = p[cur];
	}
	set<int> s;
	int vv =0;
	while (!route.empty()) {
		int v = route.top(); route.pop();
		int in = (s.size()+k-v)/2;
		int notin = k-in;
		vi qarr;
		set<int> toremove;
		int c = 0;
		for (auto i: s) {
			if (c==in) break;
			qarr.push_back(i);
			toremove.insert(i);
			c++;
		}
		set<int> toadd;
		c=0;
		REPL(i, 1,n+1) {
			if (c==notin) break;
			if (s.find(i)==s.end()) {
				qarr.push_back(i);
				c++;
				toadd.insert(i);
			}
		}

		for (auto i: toremove){
			s.erase(i);
		}
		for (auto i: toadd) {
			s.insert(i);
		}
		vv^= ask(qarr);

	}
	printres(vv);
}