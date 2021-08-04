// https://codeforces.com/contest/1554/problem/B
//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;

void solve() {
	cin >> n >> k;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; ++ i) {
		cin >> v[i];
	}

	int ans = INT_MIN;

	for(int i = 1; i <= n; ++ i) {
		for(int j = i + 1; j <= min(n, i + (n * k + i) / i); ++ j) {
			ans = max(ans, i * j - k * (v[i] | v[j]));
		}
	}

	cout << ans << "\n";
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