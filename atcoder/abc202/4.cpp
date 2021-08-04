//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int a, b, k;

void solve() {
	cin >> a >> b >> k;

	vector<vector<int>> dp(a + 1, vector<int> (b + 1, 0));

	dp[0][0] = 1;

	for(int i = 0; i <= a; ++ i) {
		for(int j = 0; j <= b; ++ j) {
			if(i > 0) {
				dp[i][j] += dp[i - 1][j];
			}
			if(j > 0) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}

	while(a > 0 && b > 0) {
		if(k <= dp[a - 1][b]) {
			cout << 'a';
			-- a;
		} else {
			k -= dp[a - 1][b];
			cout << 'b';
			-- b;
		}
	}

	cout << (string(a, 'a'));
	cout << (string(b, 'b'));
}

int32_t main() {
	#ifndef ONLINE_JUDGE
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

	return 0;
}