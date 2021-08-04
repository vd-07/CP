//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m, c, f;

void solve() {
	cin >> n >> m;

	cin >> c;

	int cx[c], cy[c];
	pair<int, int> cxy[n];
	for(int i = 0; i < c; ++ i) {
		cin >> cx[i] >> cy[i];
		cxy[i].first = cx[i];
		cxy[i].second = cy[i];
	}

	sort(cx, cx + c);
	sort(cy, cy + c);

	int mx = cx[c / 2], my = cy[c / 2];

	cin >> f;

	int maxDist = n + m;
	int idx = -1;
	int x2, y2;

	// cerr << mx << " " << my << endl;

	for(int i = 0; i < f; ++ i) {
		int x, y;
		cin >> x >> y;

		if(abs(mx - x) + abs(my - y) < maxDist) {
			maxDist = abs(mx - x) + abs(my - y);
			idx = i + 1;
			x2 = x, y2 = y;
		}
	}

	maxDist = 0;
	for(int i = 0; i < c; ++ i) {
		int x1 = cxy[i].first, y1 = cxy[i].second;
		if(abs(x1 - x2) + abs(y1 - y2) > maxDist) {
			maxDist = abs(x1 - x2) + abs(y1 - y2);
		}
	}
	cout << maxDist << "\n";
	cout << idx;
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