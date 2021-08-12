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
void ask(int t,int i,int j,int x) {
	cout<<"? "<<t<<" "<<i<<" "<<j<<" "<<x<<endl;
}
void solve() {
	int n;
	cin>>n;
	vi arr(n,-1);
	REP(i, n) {
		if (i+1==n) break;
		ask(2,i+1,i+2,1);
		int minamt;
		cin>> minamt;
		if (minamt == 2) {
			ask(2,i+2,i+1,1);
			int x;
			cin>>x;
			minamt = min(x, minamt);
		}
		ask(1, i+1,i+2, n-1);
		int maxamt;
		cin>>maxamt;
		if (maxamt == n-1) {
			ask(1, i+2,i+1, n-1);
			int x;
			cin>>x;
			maxamt = max(x, maxamt);
		}
		ask(2, i+1,i+2, minamt);
		int chk;
		cin>>chk;
		if (chk == minamt) {
			arr[i] = minamt;
			arr[i+1] = maxamt;
		} else {
			arr[i] = maxamt;
			arr[i+1] = minamt;
		}
		i++;
	}
	if (n%2 ==1) {
		set<int> s;
		REP(i, n) {
			s.insert(i+1);
		}
		REP(i, n-1) {
			s.erase(arr[i]);
		}
		arr[n-1] = *s.begin();
	}

	cout<<"!"<<" ";
	for (auto i: arr) {
		cout<<i<<" ";
	}cout<<endl;
}

int main()
{
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}