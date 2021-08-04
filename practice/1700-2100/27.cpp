//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void solve() {
	long long a, b;
	cin >> a >> b;

	vector<int> ancestorsOfA, ancestorsOfB;

	while(a) {
		ancestorsOfA.push_back(a);
		a /= 2;
	}

	while(b) {
		ancestorsOfB.push_back(b);
		b /= 2;
	}

	int cycleLength = 0;
	for(int i = 0; i < (int)ancestorsOfA.size() && cycleLength == 0; ++ i) {
		for(int j = 0; j < (int)ancestorsOfB.size(); ++ j) {
			if(ancestorsOfB[j] == ancestorsOfA[i]) {
				cycleLength = j + i + 1;
				break;
			}
		}
	}
	cout << cycleLength << "\n";
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