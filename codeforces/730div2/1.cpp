//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int a, b;

int calc(int n, int diff) {

	n *= diff;

	// cerr << n << endl;

	return abs(b - n);
}

void solve() {
	cin >> a >> b;

	if(a < b) {
		swap(a, b);
	}

	int diff = a - b;

	int ans = 0;

	if(diff != 0) {
		// cerr << diff << " " << b << endl;
		ans = min(calc(b / diff, diff), calc((b + diff - 1) / diff, diff));
	}

	cout << diff << " " << ans << "\n";
 }

int32_t main() {
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    // this can be opted out if you want to print the output to the sublime console
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

	return 0;
}