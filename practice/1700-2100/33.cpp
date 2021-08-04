//Author : Vivek Dubey
// https://codeforces.com/problemset/problem/1527/B2
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void solve() {
	cin >> n;

	char c[n];
	for(char &i: c) cin >> i;

	int x = 0, y = 0;
	for(int i = 0; i < n; ++ i) {
		if(c[i] == '0') {
			++ y;
			if(c[i] != c[n - i - 1]) ++ x;	
		}
	}
	y -= x;

	int alice = 0;
	if(y & 1) {
		// what if only one '0' in the middle
		alice = max(1ll, (y - 1) / 2);
	} else {
		if(x) {
			alice = y / 2;
		} else {
			alice = (y + 2) / 2;
		}
	}

	int bob = x + y - alice;

	if(alice == bob) {
		cout << "DRAW\n";
	} else if(alice < bob) {
		cout << "ALICE\n";
	} else {
		cout << "BOB\n";
	}
}

int32_t main() {
	#ifdef CODINGINVEINS
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	// for fast i/o
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	// test cases
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}