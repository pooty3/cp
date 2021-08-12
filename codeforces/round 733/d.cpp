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

void solve() {
	int n;
	cin>>n;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];arr[i]--;
	}
	set<int> unassigned;
	int can = 0;
	REP(i, n) {
		unassigned.insert(i);
	}
	vi farr(n,-1);
	REP(i, n) {
		if (unassigned.find(arr[i])!=unassigned.end()) {
			farr[i] = arr[i];
			can++;
			unassigned.erase(arr[i]);
		} 
	}
	if (unassigned.size() == 1) {
		int v;
		REP(i, n) {
			if (farr[i] == -1) {
				v = i; break;
			}
		}
		if (v == *unassigned.begin()) {
			int needed = arr[v];
			REP(i, n) {
				if (farr[i] == needed) {
					farr[i] = -1;
				}
			}
			farr[v] = arr[v];
		}
	}
	vi dofirst;
	REP(i, n) {
		if (farr[i]== -1 && (unassigned.find(i)!=unassigned.end())) {
			dofirst.push_back(i);
		}
	}
	if (dofirst.size()==1) {
		auto it = unassigned.begin();
		if (*it == dofirst[0]) {
			it = next(it);
		} 
		farr[dofirst[0]] = *it;
		unassigned.erase(it);
	} else {
		REP(i, dofirst.size()) {
			farr[dofirst[i]] = dofirst[(i+1)%dofirst.size()];
		}
		for (auto i : dofirst) {
			unassigned.erase(i);
		}
	}
	REP(i, n) {
		if (farr[i] == -1) {
			farr[i] = *(unassigned.begin());
			unassigned.erase(unassigned.begin());
		} 
	}
	cout<<can<<"\n";
	REP(i, n) {
		cout<<farr[i]+1<<" ";
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