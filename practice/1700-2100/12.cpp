// https://codeforces.com/contest/1324/problem/E

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e3 + 10;

int n, h, l, r;
int a[N];
int dp[N][N];

int recur(int i, int ct) {
	if(i == n) {
		return 0;
	}

	if(dp[i][ct] != -1) {
		return dp[i][ct];
	}

	int c1 = 0, c2 = 0;
	int ct1 = (ct + a[i]) % h;
	int ct2 = (ct + a[i] - 1) % h;

	if(ct1 <= r && ct1 >= l) {
		c1 = 1;
	}

	if(ct2 <= r && ct2 >= l) {
		c2 = 1;
	}

	return dp[i][ct] = max(c1 + recur(i + 1, ct1), c2 + recur(i + 1, ct2));

}

void solve() {
	cin >> n >> h >> l >> r;

	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < h; ++ j) {
			dp[i][j] = -1;
		}
	}

	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
	}

	cout << recur(0, 0);
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