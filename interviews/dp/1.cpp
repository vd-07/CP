//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

const int mxN = 3e5 + 1;

int n, m;
string a, b;
vector<vector<int>> dp;

int recur(int i, int j) {
	if(i == n || j == m) {
		return n - i + m - j;
	}

	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	if(a[i] == b[j]) {
		return dp[i][j] = recur(i + 1, j + 1);
	}

	int v1 = recur(i, j + 1) + 1,
		v2 = recur(i + 1, j) + 1,
		v3 = recur(i + 1, j + 1) + 1;

	return dp[i][j] = min({v1, v2, v3});
}

void solve() {
	cin >> a >> b;
	n = a.size(), m = b.size();

	dp = vector<vector<int>> (n, vector<int> (m, -1));

	cout << recur(0, 0);
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