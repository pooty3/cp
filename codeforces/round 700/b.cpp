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
	int segs= 1;
	int ind = -1;
	vii chunks;

	REPL(i,1, n) {
		if (arr[i]!=arr[i-1]) {
			segs++;
			if (ind != -1) {
				chunks.push_back({ind,i-1});
			}
			ind = -1;
		} else {
			if (ind == -1) {
				ind= i-1;
			}
		}
	}
	if (ind!=-1) {
		chunks.push_back({ind, n-1});
	}
	if (chunks.size()>0) {
		segs++;
	}
	REPL(i, 1,chunks.size()) {

		int e = chunks[i].first-1;
		int s = chunks[i-1].second +1;
		if (arr[e+1]!=arr[s-1]) {
			segs++;
		} else {

			if (s!=e) {
				if ((e-s+1)%2==0) {
					segs++;
				}
				else {
					int chunkval = arr[e+1];
					int cur = s+1;
					while (cur<=e) {
						if (arr[cur]!=chunkval) {
							segs++;
							break;
						}
						cur += 2;
					}
				}
			}

		}

	}
	cout<<segs;


}