//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

const int mod = 1e9 + 7;

int n;

void solve() {
	cin >> n;

	int ans = 1;

	int c[n];

	for(int i = 0; i < n; ++ i) {
		cin >> c[i];
	}

	sort(c, c + n);

	for(int i = 0; i < n; ++ i) {
		ans *= max(0ll, c[i] - i);
		ans %= mod;
	}

	cout << ans;
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
	
	while(t--) {
		solve();
	}

	return 0;
}