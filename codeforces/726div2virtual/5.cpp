//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

bool func(int num, bool who) {
	int cnt = 0;

	for(int i = 2; i * i <= num; ++ i) {
		if(num % i) continue;
		cnt ++;
		bool ok1 = func(num - (num / i), who ^ 1);
		bool ok2 = func(num - i, who ^ 1);

		if(who) {
			if(ok1 || ok2) {
				return true;
			}
		} else {
			if((!ok1) || (!ok2)) {
				return false;
			}
		}
	}

	if(cnt == 0) {
		// cannot play
		return who ^ 1;
	}

	// not able to win
	return who ^ 1;
}

void solve() {
	for(int i = 1; i <= 1000; i *= 2) {
		cerr << i << " : ";
		if(func(i, 1)) {
			cerr << "ALICE\n";
		} else {
			cerr << "BOB\n";
		}
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