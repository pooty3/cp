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
	int n;
	cin>>n;
	vi arr(n);
	REP(i, n) {
		cin>>arr[i];
	}
	set<int> peaks;
	REPL(i, 1, n-1) {
		if (arr[i]> arr[i-1]&&arr[i]>arr[i+1]) {
			peaks.insert(i);
		}
	}
	int mxheight = 0;
	bool able = false;
	FOREACH(it, peaks) {
		int id = *it;
		int left = 1;
		int curl = arr[id];
		while (true){
			if (id == 0) break;
			if (curl> arr[id-1]) {
				curl = arr[id-1];
				id--;
				left++;
			} else {
				break;
			}
		}
		id = *it;
		int right = 1;
		int curr = arr[id];
		while (true) {
			if (id ==n-1) break;
			if (curr > arr[id+1]) {
				curr = arr[id+1];
				id++;
				right++;
			} else {
				break;
			}
		}
		if (max(left, right) == mxheight) {
			able = false;
		} else if (max(left, right) > mxheight) {
			mxheight = max(left, right);
			if (left != right) {
				able = false;
			} else if (left%2 ==0) {
				able = false;
			} else {
				able = true;
			}
		}else {}
	}
	if (able) {
		int mxhr=1,mxhl = 1;
		REP(i, n) {
			if (arr[i]<arr[i+1]) {
				break;
			} else {
				mxhr++;
			}
		}
		REP(i, n) {
			if (arr[n-1-i]<arr[n-2-i]) {
				break;
			} else {
				mxhl++;
			}
		}
		if (max(mxhr,mxhl) < mxheight) {
			cout<<1;
		} else {
			cout<<0;
		}

	} else {
		cout<<0;
	}

}