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

void ask(int i) {
	cout<<"?"<<" "<<i<<endl;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n;
	cin>>n;
	int left = 0;
	int right = n+1;
	int k = n%2==0? n/2: n/2 + 1;
	ask(k);
	int valM;
	cin>>valM;
	int mid = k;

	while (left+2 < right) {
		int nL = left;
		if (left+1 < mid) {
			nL = (left + mid)/2;
			ask(nL);
			int val;
			cin>>val;
			if (val < valM) {
				valM = val;
				right = mid;
				mid = nL;
				continue;
			}
		}
		int nR = right;
		if (mid+1 < right) {
			nR = (right + mid)/2;
			ask(nR);
			int val;
			cin>>val;
			if (val < valM) {
				valM = val;
				left = mid;
				mid = nR;
				continue;
			}
		}
		left = nL;
		right = nR;
	}
	cout<<"!"<<" "<<mid<<endl;
}	