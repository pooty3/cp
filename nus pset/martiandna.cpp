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

vi arr;
vi narr;
int tot=0;

bool able (int len) {
	int curtot = tot;
	vi curarr = narr;
	REP(i, len) {
		int c = arr[i];
		curarr[c]--;
		if (curarr[c]>=0) {
			curtot--;
		}
	}
	if (curtot ==0) {
		return true;
	} 
	REPL(i, len, arr.size()) {
		int c = arr[i];
		int b = arr[i-len];
		curarr[c]--;
		if (curarr[c]>=0) {
			curtot--;
		} 
		curarr[b]++;
		if (curarr[b]>0) {
			curtot ++;
		}
		if (curtot ==0) {
			return true;
		}

	} return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,k,r;
	cin>>n>>k>>r;
	arr.assign(n,0);
	REP(i, n) {
		cin>>arr[i];
	}
	narr.assign(n, 0);
	REP(i, r) {
		int b, v;
		cin>>b>>v;
		tot +=v;
		narr[b] = v;
	}
	if (!able(n)) {
		cout<<"impossible";
	} else {
		int mx = n;
		int mn = tot;
		while (mx>mn) {
			int cur = (mx+mn)/2;
			if (able(cur)) {
				mx = cur;
			} else {
				mn = cur+1;
			}
		}
		cout<<mx;
	}

}