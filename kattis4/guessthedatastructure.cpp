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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int  n;
	while (cin>>n) {
		bitset<3> bs;
		bs.set();
		priority_queue<int> pq;
		stack<int> s;
		queue<int> q;
		int c =0;
		REP(i, n) {
			int u,v;
			cin>>u>>v;
			if (u==1) {
				c++;
				pq.push(v);
				s.push(v);
				q.push(v);
			}
			if (u==2) {
				if (c==0) bs.reset();
				else {
					if (pq.top()!=v) {
						bs[0] = 0;
					}
					if (s.top()!=v) {
						bs[1] =0;
					} 
					if (q.front()!=v) {
						bs[2]=0;
					}
					pq.pop();
					s.pop();
					q.pop();
					c--;
				}
			}
		}
		if (bs.count()==0) {
			cout<<"impossible\n";
		}
		if (bs.count() >1) {
			cout<<"not sure\n";
		} 
		if (bs.count()==1) {
			if(bs[0]==1) {
				cout<<"priority queue\n";
			}
			if(bs[1]==1) {
				cout<<"stack\n";
			}
			if(bs[2]==1) {
				cout<<"queue\n";
			}
		}
	}
}