//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;
int h[mxN];

void solve() {
	cin >> n;

	for(int i = 0; i < n; ++ i) {
		cin >> h[i];
	}

	sort(h, h + n);
	int id = 0;
	int minDiff = h[n - 1] - h[0] + 2;

	for(int i = 0; i + 1 < n; ++ i) {
		if(h[i + 1] - h[i] < minDiff) {
			minDiff = h[i + 1] - h[i];
			id = i;
		}
	}

	cout << h[id] << " ";
	for(int i = id + 2; i < n; ++ i) {
		cout << h[i] << " ";
	}
	for(int i = 0; i < id; ++ i) {
		cout << h[i] << " ";
	}
	cout << h[id + 1] << "\n";

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