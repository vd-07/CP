//Author : Vivek Dubey
#include <iostream>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int W, H, x1, y1, x2, y2, w, h;

void solve() {
	cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

	int cost = 1e12;

	if(y2 - y1 + h <= H) {
		cost = min(cost, min(h - y1, y2 - H + h));	
	}
	
	if(x2 - x1 + w <= W) {
		cost = min(cost, min(w - x1, x2 - W + w));	
	}
	
	cost = max(cost, 0ll);

	if(x2 - x1 + w > W && y2 - y1 + h > H) {
		cost = -1;
	}

	cout << cost << "\n";
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