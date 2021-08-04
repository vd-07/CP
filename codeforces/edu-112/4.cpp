//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m;

void solve() {
	cin >> n >> m;
	string s;
	cin >> s;

	vector<vector<int>> prefix;
	string allowed = "abc";

	do {	
		vector<int> currPrefix(n + 1);
		for(int i = 0; i < n; ++ i) {
			currPrefix[i + 1] = (s[i] == allowed[i % 3]);
		}
		for(int i = 1; i <= n; ++ i) {
			currPrefix[i] += currPrefix[i - 1];
		}
		prefix.push_back(currPrefix);
	} while(next_permutation(allowed.begin(), allowed.end()));

	while(m --) {
		int l, r;
		cin >> l >> r;

		int totalSize = r - l + 1;
		int ans = totalSize;

		for(int i = 0; i < 6; ++ i) {
			int currAns = totalSize - (prefix[i][r] - prefix[i][l - 1]);
			ans = min(ans, currAns);
			// cerr << ans << endl;
		}

		cout << ans << "\n";
	}
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