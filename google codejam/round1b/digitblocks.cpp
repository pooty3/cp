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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int t,n,b;
	ll p;
	cin>>t>>n>>b>>p;
	REP(zz, t) {
		int curtop1 = 1;
		int curtop2 = 1;
		int curbuild = 1;
		int curh = 0;
		REP(iii, n*b) {
			int x;cin>>x;
			int rem = n*b-iii;
			int needed1 = n-curtop1;
			int needed2 = n-curtop2;
			if (curbuild == n+1) {
				if (curtop2 == n+1) {
					cout<<(curtop1)<<endl; curtop1++; continue;
				}
				if (curtop2 == curtop1) {
					cout<<(curtop2)<<endl; curtop2++;continue;
				}
				if (x*rem>=9*(rem-needed1)) {
					cout<<curtop1<<endl;
					curtop1++;continue;
				} else {
					cout<<curtop2<<endl;
					curtop2++;continue;
				}
			}
			if (curtop1 == curbuild) {
				cout<<(curbuild)<<endl;
				curh++; 
				if (curh == b-2) {
					curh = 0;curbuild++;
				}continue;
			}
			if (curtop2 == curbuild) {
				if (x*rem >=9*( rem-needed1)) {
					cout<<curtop1<<endl;
					curtop1++;continue;
				} else {
					cout<<curbuild<<endl;
					curh++; 
					if (curh == b-2) {
						curh = 0;curbuild++;
					}continue;
				}
			}
			if (x*rem >=9*( rem-needed1- needed2)) {
				if (needed1 == needed2 || x*rem < 9*( rem-needed1)) {
					cout<<curtop2<<endl;curtop2++;continue;
				} else {
					cout<<curtop1<<endl;curtop1++;continue;
				}
			}	else {
				cout<<curbuild<<endl;
				curh++; 
				if (curh == b-2) {
					curh = 0;curbuild++;
				}continue;
			}
		}
	}

}