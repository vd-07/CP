//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, t;
int a[mxN];

void solve() {
	cin >> n >> t;
	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
	}

	int ans = 0;

	int last = 0;
	int sumOfTime = 0;

	for(int i = 0; i < n; ++ i) {
		sumOfTime += a[i];
		while(sumOfTime > t && last <= i) {
			sumOfTime -= a[last++];
		}
		ans = max(i - last + 1, ans);
	}

	cout << ans;
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