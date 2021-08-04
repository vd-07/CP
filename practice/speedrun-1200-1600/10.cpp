//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;

void solve() {
	cin >> n;
	string s;
	cin >> s;

	string a = "1", b = "1";
	bool turn = true;

	for(int i = 1; i < n; ++ i) {
		int curr = s[i] - '0';

		if(curr == 1) {
 			if(turn) {
 				a += '1';
 				b += '0';
 				turn = false;
 			} else {
 				a += '0';
 				b += '1';
 			}
		} else {
			if(turn) {
				a += char((curr / 2) + '0');
				b += char((curr / 2) + '0');	
			} else {
				b += (char(curr) + '0');
				a += '0';
			}
		}
	}

	cout << a << "\n";
	cout << b << "\n";
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