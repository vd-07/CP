//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

bool findSum(int sum) {
	bool dp[n + 1][sum + 1] = {};

	for(int i = 0; i <= n; i++) {
		dp[i][0] = true;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= sum; j++) {
			if(j < a[i - 1]) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
			}

		}
	}
	return dp[n][sum];
}

void solve() {
	cin >> n;

	int sum = 0;
	int maxNo = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		maxNo = max(maxNo, a[i]);
	}

	if(sum % 2 == 1) {
		cout << "0";
		return;
	}

	bool ok = findSum(sum / 2);

	if(ok == false) {
		cout << "0";
		return;
	}

	int div = 2;

	cout << "1\n";
	while(div <= maxNo) {
		for(int i = 0; i < n; i++) {
			if(a[i] % div != 0) {
				cout << i + 1;
				return;
			}
		}
		div *= 2;
	}

	cout << "1";
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