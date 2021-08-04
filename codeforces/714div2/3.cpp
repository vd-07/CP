//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;
const int mod = 1e9 + 7;

int n, m;
int f[mxN];

void process() {
	for(int i = 0; i < 10; i++) {
		f[i] = 1;
	}

	for(int i = 10; i < mxN; i++) {
		f[i] = f[i - 10] + f[i - 9];
		f[i] %= mod;
	}
}

int calc(int digit, int m) {
	return f[m + digit];
}

void solve() {
	cin >> n >> m;

	int ans = 0;

	while(n) {
		int digit = n % 10;

		ans += calc(digit, m);

		// cerr << ans << " " << digit << endl;
		ans %= mod;

		n /= 10;
	}
	cout << ans << "\n";
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

	process();

	// test cases
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}