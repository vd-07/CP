//Author : Vivek Dubey
// https://cses.fi/problemset/task/1068
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

// int make(int d) {
// 	if(d == 0) ++ d;
// 	int no = 0;
// 	while(no <= n) {
// 		no = no * 10 + d;
// 	}

// 	return no;
// }

void solve() {
	cin >> n;
	
	// int ans = 3e18;
	// for(int i = 1; i <= 9; ++ i) {
	// 	ans = min(ans, make(i));
	// }

	// cout << ans << "\n";
	cin >> n;
	n *= 2;
	while(n != 1) {
		n = (n & 1) ? 3 * n + 1 : n / 2;
		cout << n << " ";

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
	// cin >> t;
	while(t--) {
		solve();
	}

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}