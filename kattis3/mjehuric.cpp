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

void print2(vi &arr) {
	REP(i, 5) {
		cout<<arr[i]<<" ";
	}cout<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vi arr(5);
	REP(i, 5) {
		cin>>arr[i];
	}
	while (true) {
		REP(i, 4) {
			if (arr[i+1] < arr[i]) {
				int temp = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = temp;
				print2(arr);
			}
		}
		if (is_sorted(arr.begin(), arr.end())) break;
	}
}