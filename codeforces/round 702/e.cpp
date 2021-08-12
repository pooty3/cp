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
	int n1,n2,n3,n4;
	cin>>n1>>n2>>n3>>n4;
	vi arr1(n1),arr2(n2),arr3(n3);
	set<ii> mp4;
	REP(i, n1) {
		cin>>arr1[i];
	}
	REP(i, n2) {
		cin>>arr2[i];
	}
	REP(i, n3) {
		cin>>arr3[i];
	}
	REP(i, n4) {
		int v;
		cin>>v;
		mp4.insert({v, i});
	}
	set<ii> s1,s2,s3;
	int m;
	cin>>m;
	REP(i,m) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		s1.insert({u,v});
	}
	cin>>m;
	REP(i,m) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		s2.insert({u,v});
	}
	cin>>m;
	REP(i,m) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		s3.insert({u,v});
	}
	set<ii> mp1,mp2,mp3;
	REP(i, n3) {
		for (auto it = mp4.begin(); it != mp4.end(); it++) {
			int v = it->second;
			if (s3.find({i,v})== s3.end()) {
				mp3.insert({arr3[i] + it->first, i});
				break; 
			}
		}
	}
	REP(i, n2) {
		for (auto it = mp3.begin(); it != mp3.end(); it++) {
			int v = it->second;
			if (s2.find({i,v})== s2.end()) {
				mp2.insert({arr2[i] + it->first, i});
				break; 
			}
		}
	}

	REP(i, n1) {
		for (auto it = mp2.begin(); it != mp2.end(); it++) {
			int v = it->second;
			if (s1.find({i,v})== s1.end()) {
				mp1.insert({arr1[i] + it->first, i});
				break; 
			}
		}
	}
	if (mp1.size()==0) {
		cout<<-1;
	} else {
		cout<<(mp1.begin())->first;
	}
}