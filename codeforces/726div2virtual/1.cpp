//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m, i, j;

// struct Ans {
// 	int x1, y1, x2, y2;
// };

int dist(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}

int calcTotalTravel(int x1, int y1, int x2, int y2) {
	return dist(i, j, x1, y1) + dist(i, j, x2, y2) + dist(x1, y1, x2, y2);
}

void solve() {
	cin >> n >> m >> i >> j;

	int dist = -1;
	vector<int> ans = {0, 0, n - 1, m - 1};

	for(int c: ans) {
		cout << c + 1 << " ";
	}
	cout << "\n";
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