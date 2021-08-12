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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true) {
		int n;
		cin>>n;
		if (n==0) break;
		int arr[n];
		vii sol(n);
		int curind = -1;
		int curl = 0;
		int cval = INF;
		REP(i, n) {
			cin>>arr[i];
			int cur = -1;
			int l = 0;
			int val =INF;
			REP(j, i) {
				if (arr[j]< arr[i]) {
					if (sol[j].second > l||(sol[j].second==l && val > arr[j])) {
						l = sol[j].second;
						cur = j;
						val = arr[j];
					} 
				}
			}
			sol[i] = {cur, l+1};
			if (sol[i].second> curl ||(arr[i] < cval && sol[i].second == curl )) {
				curl = sol[i].second;
				curind = i;
				cval = arr[i];
			}
		}
		int cur = curind;
		vi ar;
		while (cur !=-1) {
			ar.push_back(arr[cur]);
			cur = sol[cur].first;
		}
		cout<<ar.size()<<" ";
		REP(i, ar.size()) {
			cout<<ar[ar.size()-1-i]<<" ";
		}
		cout<<"\n";
	}

}