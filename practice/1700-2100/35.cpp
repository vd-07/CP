//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m, k;

void solve() {
	cin >> n >> m >> k;

	if(m & 1) {
		swap(n, m);
		k = (n * m) / 2 - k;
	}

	// cerr << n << " " << m << " " << k << endl;
	if(n & 1) {
		int x = m / 2;

		if(k < x) {
			cout << "NO\n";
			return;
		}

		k -= x;
	}
	
	if(k & 1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
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