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
	int r,s,k;
	cin>>r>>s>>k;
	int arr[r][s];
	vector<string> strs(r);
	memset(arr, 0,sizeof(arr));
	REP(i, r) {
		cin>>strs[i];
		REP(j, s) {
			arr[i][j] = strs[i][j]=='*'?1:0;
			if (i>0) arr[i][j] += arr[i-1][j];
			if (j>0) arr[i][j] += arr[i][j-1];
			if (i>0 && j>0) arr[i][j]-=arr[i-1][j-1];
		}
	}

	int mn =0, mi =0, mj=0;
	REP(i, r-k+1) {
		REP(j, s-k+1) {
			int val = arr[i+k-2][j+k-2] - arr[i][j+k-2] - 
		arr[i+k-2][j] + arr[i][j];
			if (val >mn) {
				mn = val;
				mi = i;
				mj = j; 
			}
		}
	}
	REP (i, k) {
		if (i==0||i == k-1){
			strs[mi][mj+i] = '+';
			strs[mi+k-1][mj+i] = '+';
		}
		else {
			strs[mi+k-1][mj+i] = '-';

			strs[mi][mj+i] = '-';
		}
	}
	REPL(i,1, k-1) {
		strs[mi+i][mj] = '|';
		strs[mi+i][mj+k-1] ='|';
	}
	cout<<mn<<"\n";
	REP(i, r) {
		cout<<strs[i]<<"\n";
	}

}