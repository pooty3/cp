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

vector<vii> arr;
vi items;

bool possible(int val, int x) {
	if (val <0){ 
		return false;
	}
	if (val==0) {
		return true;
	}
	else {
		if(arr[val][x].first == -1) {
			vi ablearr;
			REP(i, x+1) {
				if (possible(val - items[i], i)) {
					ablearr.push_back(i);
				}
			}
			if (ablearr.size()==0) {
				arr[val][x] = {0,-1};
			} else {
				if (ablearr.size()==1) {
					arr[val][x] = {1, ablearr[0]};
				} else {
					arr[val][x] = {1, -1};
				}
			}
		}
		return arr[val][x].first;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	arr.assign(30001, vii(n, {-1, -1}));
	items.assign(n, 0);
	REP(i, n) {
		cin>>items[i];
	}
	int m;
	cin>>m;
	REP(i, m) {
		int x;
		cin>>x;
		if (!possible(x, n-1)) {
			cout<<"Impossible";
		} else {
			vi arr2;
			int curind= n-1;
			bool able = true;
			while (x!=0) {
				int item = arr[x][curind].second;
				if (item ==-1) {
					able = false;
					break;
				} else {
					arr2.push_back(item+1);
					curind = item;
					x -= items[item];
				}
			}
			if (able) {
				SORT(arr2);
				FOREACH(it, arr2) {
					cout<<(*it)<<" ";
				}
			} else {
				cout<<"Ambiguous";
			}
		}
		cout<<"\n";
	}

}