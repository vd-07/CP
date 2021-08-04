// https://codeforces.com/contest/467/problem/C

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e3 + 10;

int n, m, k;
int a[N];
int dp[N][N];

void solve() {

	for(int i = 0; i < N; ++ i) {
		for(int j = 0; j < N; ++ j) {
			dp[i][j] = 0;
		}
	}

	cin >> n >> m >> k;

	a[0] = 0;

	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];

		a[i] += a[i - 1];
	}

	while(k --) {
		for(int i = m; i <= n; ++ i) {
			int sum = a[i] - a[i - m];
			dp[i][k] = max(sum + dp[i - m][k + 1], dp[i - 1][k]);
		}
	}

	cout << dp[n][0];
}


signed main() {
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int t = 1;
	// cin >> t;

	while(t--) {
		solve();
	}

	
	return 0;
}