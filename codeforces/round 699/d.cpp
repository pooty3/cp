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
	int n,m;
	cin>>n>>m;
	char arr[n][n];
	REP(i,n) {
		string str;
		cin>>str;
		REP(j, n) {
			arr[i][j] = str[j];
		}
	}
	if (m%2==1) {
		cout<<"YES\n";
		REP(i, m+1) {
			cout<<(i%2==0? 1:2)<<" ";
		}
	} else {
		REP(i, n) {
			REP(j, n) {
				if (i==j) continue;
				if (arr[i][j]==arr[j][i]) {
					cout<<"YES\n";
					REP(z,m+1) {
						cout<<(z%2==0? (i+1):(j+1))<<" ";
					}
					goto DONE;
				}
			}
		}
		REP(i, n) {
			int ina = -1;
			int outa = -1;
			REP(j, n) {
				if (arr[i][j]=='a') {
					outa = j;
				} 
				if (arr[j][i]=='a') {
					ina = j;
				}
			}
			if (ina!=-1 && outa!=-1) {
				vi seq = {outa+1,i+1, ina+1, i+1};
				int offset = m%4==2? 0: 1;
				cout<<"YES\n";
				REP(i, m+1) {
					cout<<seq[(i + offset)%4]<<" ";
					
				}
				goto DONE;
			}
		}
		cout<<"NO\n";

	}
	DONE:
	cout<<"\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}