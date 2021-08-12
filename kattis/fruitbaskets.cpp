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

vi arr;
ll rem(int ind, int cur) {
	if (ind < arr.size()){
		ll rem1=0;
		if (cur < 200){
			rem1 = rem(ind+1, cur+ arr[ind]);
		}
		ll rem2 = rem(ind+1, cur);
		return rem1+rem2;
	}
	else {
		if (cur<200) {
			return cur;
		} else {
			return 0;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	ll sum =0;
	arr.assign(n,0);
	REP(i,n) {
		cin>>arr[i];
		sum+=arr[i];

	}
	sum *= (1LL<<(n-1));
	cout<< (sum - rem(0,0));

}