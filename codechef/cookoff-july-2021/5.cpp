//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int N = 4e4 + 1;
const int mod = 1e9 + 7;

void solve() {
	int n;
	cin >> n;

	vector<int> cost(10);

	for(int i = 1; i <= 9; ++ i) {
		cin >> cost[i];
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