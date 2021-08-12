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
	int a,b,k;
	cin>>a>>b>>k;
	if ((k>= a+b-1||(a==0||b==1))&&k!=0) {
		cout<<"No";
		return;
	}
	vi arr1(a+b),arr2(a+b);
	if (k==0) {
		REP(i, b) {
			arr1[i]= arr2[i] = 1;
		}	
		REP(i, a) {
			arr1[b+i] = arr2[b+i] = 0;
		}
	} else {
		int presize = (a+b-1-k);
		int aftersize = k-1;
		arr1[presize] = 1;
		arr2[presize] = 0;
		arr1[a+b-1] = 0;
		arr2[a+b-1] = 1;
		a--;b--;
		REP(i, presize) {
			if (b>0) {
				arr1[i] = arr2[i] = 1;
				b--;
			} else {
				arr1[i] = arr2[i] = 0;
			}	
		}
		REP(i, aftersize) {
			if (b>0) {
				arr1[i+1+presize] = arr2[i+1+presize] = 1;
				b--;
			} else {
				arr1[i+1+presize] = arr2[i+1+presize] = 0;
			}
		}
	}
	cout<<"Yes\n";
	REP(i, arr1.size()) {
		cout<<arr1[i];
	}cout<<"\n";
	REP(i, arr2.size()) {
		cout<<arr2[i];
	}cout<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	solve();

}