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

ll dist(vii &arr, int k) {
	int i = arr.size()-1;
	ll tot=0;
	int load=0;
	while(i>=0) {
		if (arr[i].second ==0) {
			i--;
		}
		else if (load < arr[i].second) {
			int topup = arr[i].second - load;
			int top;
			if (topup%k==0) {
				top = topup/k;
			} else {
				top = topup/k +1;
			}
			load += top*k;
			tot += arr[i].first*2*top;
		} else {
			load -= arr[i].second;
			arr[i].second = 0;
		}
	}
	return tot;
}

int main()
{
	int n,k;
	cin>>n>>k;
	vii arr1, arr2;
	REP(i, n) {
		int x,t;
		cin>>x>>t;
		if (x<0) {
			arr2.push_back({abs(x),t});
		} else {
			arr1.push_back({x,t});
		}
	}
	SORT(arr1);
	SORT(arr2);
	cout<<(dist(arr1, k)+ dist(arr2, k));

}