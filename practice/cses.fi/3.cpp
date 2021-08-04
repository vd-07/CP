//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void solve() {
	string s;
	cin >> s;

	int ans = 0;
	int count = 1;
	for(int i = 1; i < (int)s.size(); ++ i) {
		if(s[i] == s[i - 1]) {
			++ count;
		} else {
			ans = max(ans, count);
			count = 1;
		}
	}
	ans = max(ans, count);
// 	for(char c: {'A', 'T', 'G', 'C'}) {
// 		int count = 0;
// 		for(char t: s) {
// 			if(t == c) {
// 				++ count;
// 			} else {
// 				ans = max(ans, count);
// 				count = 0;
// 			}
// 		}
// 		ans = max(ans, count);
// 	}
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