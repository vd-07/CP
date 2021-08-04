//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define uint unsigned long long int
#define sz(a) (int)((a).size())
//read
#define READ(a) int a; cin>>a
#define READ2(a,b) int a,b; cin>>a>>b
#define READ3(a,b,c) int a,b,c; cin>>a>>b>>c
#define READ4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d
#define READC(c) char c; cin>>c
#define READA(a,n) int a[n]; for(int i = 0; i < n; i++) cin>>a[i]
#define READS(s) string s; cin>>s
//debug
#define d1(a) cerr << #a << " " << a << endl;
#define d2(a, b) cerr << #a << " " << a << " " << #b << " " << b << endl;
#define d3(a, b, c) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << endl;
#define d4(a, b, c, d) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << " " << #d << " " << d << endl;
//for loop
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
//general
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define int128 __int128
#define ff first
#define ss second

string I, O;
int n;
map<pair<int, int>, bool> result;

bool check(int country1, int country2) {
	// order does not matters, as we are checking the countries in between
	if(country1 > country2) {
		swap(country1, country2);
	}
	// if already calculated
	if(result.find({country1, country2}) != result.end()) {
		return result[{country1, country2}];
	}
	// check
	for(int i = country1 + 1; i < country2; i++) {
		if(I[i] == 'N' || O[i] == 'N') {
			return result[{country1, country2}] = false;
		}
	}
	return result[{country1, country2}] = true;
}

void solve() {
	result.clear();
	cin >> n;
	cin >> I;
	cin >> O;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) {
				cout << "Y";
				continue;
			}
			if(O[i] == 'N' || I[j] == 'N') {
				cout << "N";
				continue;
			}
			if(check(i, j)) {
				cout << "Y";
			}
			else {
				cout << "N";
			}
		}
		cout << "\n";
	}	
}

int32_t main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif
    fastIO

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
    	cout << "Case #" << i << ": \n";
	 	solve();
    }

    return 0;
}