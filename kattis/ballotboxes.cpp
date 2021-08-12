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

struct daa {
	int val;
	int ppl;
	int box;
	bool operator< (const daa& other) const{
		return this->val < other.val;
	}
};
int main()
{
	while (true) {
		priority_queue<daa> pq;
		int n,b;
		scanf("%d %d", &n, &b);
		if (n==-1) break;
		REP(i, n) {
			int x;
			scanf("%d", &x);
			pq.push({x,x,1});
		}
		REP(i, b-n) {
			daa d= pq.top();
			d.box++;
			d.val = ceil((double)d.ppl/d.box);
			pq.pop();
			pq.push(d);
		}
		printf("%d\n", pq.top().val);

	}



}