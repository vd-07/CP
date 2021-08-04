//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;
int a[mxN];

int calc(int x) {
	if(x > n) {
		return 0;
	}
	int count = 0;
	for(int i = 0; i + x - 1 < n; ++ i) {
		bool ok = true;
		for(int p1 = i; p1 < i + x && ok; ++ p1) {
			for(int p2 = p1 + 1; p2 < i + x && ok; ++ p2) {
				for(int p3 = p2 + 1; p3 < i + x && ok; ++ p3) {
					if(min(a[p1], a[p3]) <= a[p2] && a[p2] <= max(a[p1], a[p3])) {
						++ count;
						ok = false;
						break;
					}
				}
			}
		}
	}

	// total possible - bads
	return n - x + 1 - count;
}

void solve() {
	cin >> n;

	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
	}

	int ans = n + n - 1 + calc(3) + calc(4);

	// cerr << calc(4);

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