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

bool v[100][100];

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
void flood(vector<string> arr, int i, int j) {
	if (i<arr.size()&&i>=0&&j<arr[0].size()&&j>=0&&!v[i][j]&&arr[i][j]=='-') {
		v[i][j] = true;
		REP(z, 4) {
			flood(arr, i + dr[z], j + dc[z]);
		}

	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int m,n;
	int tc=0;
	while(cin>>m>>n) {
		tc++;
		vector<string> arr(m);
		REP(i, m) {
			cin>>arr[i];
		}
		memset(v, 0, sizeof(v));
		int tot =0;
		REP(i, m) {
			REP(j, n) {
				if (!v[i][j]&&arr[i][j]=='-') {
					flood(arr, i,j);
					tot++;
				}
			}
		}
		printf("Case %d: %d\n", tc, tot);
	}

}