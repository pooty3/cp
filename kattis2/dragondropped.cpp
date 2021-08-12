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
typedef complex<double> Complex;
int x,y;
int counter=0;
void ask(string str, string p) {
    counter++;
    cout<<str<<" "<<p<<endl;
    cin>>x>>y;
    if (x ==0) {
        cout<<"ASK "<<p<<endl;
        exit(0);
    }
}


int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);
	int n;cin>>n;

    int a=0;

	while (true) {
        a++;
        REP(i,2) {
            ask("NEXT", "GABBY");
        }
        ask("NEXT", "SPIKE");
        if (y==1) {
            break;
        }
	}

	/*
	ask("RETURN", "GABBY");
	int a=0;
	while (true) {
        ask("NEXT", "GABBY");
        ask("NEXT", "SPIKE");
        a++;
        if (y==1) {
            break;
        }
	}
	*/
	int len =0;
	while (true) {
        ask("NEXT", "SPIKE");
        len++;
        if (y==1) {
            break;
        }
	}
	int left = (n-a)%len;
	REP(i, left) {
        ask("NEXT", "SPIKE");
	}
	cout<<"ASK SPIKE"<<endl;
}
