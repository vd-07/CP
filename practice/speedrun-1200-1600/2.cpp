//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, l;

void solve() {
	cin >> n >> l;
	vector<int> a(n);
	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	a.push_back(2 * l - a.back());
	a.push_back(-a[0]);
	sort(a.begin(), a.end());


	int maxDist = 0;

	for(int i = 1; i <= n + 1; ++ i) {
		// cerr << a[i] << "\n";
		// cerr << maxDist << endl;
		maxDist = max(maxDist, a[i] - a[i - 1]);
	}

	double ans = (double(maxDist) / 2);
	printf("%0.12f", ans);
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