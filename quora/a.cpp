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
	int n,m;
	cin>>n>>m;
	vi stories(n);
	vvi aarr(m, vi(m, 0));
	vvi barr(m, vi(n, 0));
	REP(i, n) {
		int x;
		cin>>x;x--;
		stories[i] = x;
		barr[x][i] = 2;
	}
	int p,q;
	cin>>p>>q;
	REP(z, p) {
		int i,j;
		cin>>i>>j;i--;j--;
		aarr[i][j] = 3;
	}
	REP(z, q) {
		int i,k;
		cin>>i>>k;i--;k--;
		barr[i][k] = 1;
		aarr[i][stories[k]] = max(aarr[i][stories[k]], 2);
	}
	REP(i, m) {
		REP(j, n) {
			if (barr[i][j] == 1) {
				REP(z, m) {
					if (z==i) continue;
					if (barr[z][j] == 1) {
						aarr[i][z] = max(aarr[i][z], 1);
					}
				}
			}
		}
	}
	REP(i, m) {
		vii mp;
		REP(j, n) {
			if (barr[i][j] > 0) {
				mp.push_back({1, j});
			} else {
				int score =0;
				REP(k, m) {
					if (i==k) continue;
					score += aarr[i][k] * barr[k][j];
				} 
				mp.push_back({-score, j});
			}
		}
		SORT(mp);
		REP(i, 3) {
			cout<<(mp[i].second+1)<<" ";
		}cout<<"\n";
	}

}