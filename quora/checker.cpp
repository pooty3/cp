#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999999
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ifstream file1(argv[1]);
	ifstream file2(argv[2]);
	multiset<string> sarr;
	int cc =0;
	if (file1.is_open()) {
		string line;
		while (getline(file1, line)) {
			sarr.insert(line);
		}
	}
	file1.close();
	if (file2.is_open()) {
		string line;
		while (getline(file2, line)) {
			auto it = sarr.find(line);
			if (it == sarr.end()) {
				cout<<"Erorr!\n";
				cc++;
			} else {
				sarr.erase(it);
			}
		}		
	}
	file2.close();
	cc += sarr.size();
	cout<<"Diff: "<< cc<<"\n";

}