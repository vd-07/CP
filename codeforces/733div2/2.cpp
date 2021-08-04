//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int h, w;

void solve() {
	cin >> h >> w;

	vector<string> v(h, string(w, '0'));

	for(int i = 0; i < h; ++ i) {
		for(int j = 0; j < w; ++ j) {
			if(i == 0 || i == h - 1 || j == 0 || j == w - 1) {
				bool ok = false;
				for(int x : {1, 0, -1}) {
					for(int y : {1, 0, -1}) {
						if(i + x < 0 || i + x >= h || j + y < 0 || j + y >= w) {
							continue;
						}

						if(v[i + x][j + y] == '1') {
							ok = true;
							break;
						}
					}
				}
				if(!ok) {
					v[i][j] = '1';
				}
			}
		}
	}

	for(string s: v) {
		cout << s << "\n";
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