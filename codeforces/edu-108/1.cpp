//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int r, b, d;

bool check(int r, int b, int d) {
	if(r < b) {
		swap(r, b);
	}
	return r > 0 && b > 0 && r - b <= d;
}

void solve() {
	cin >> r >> b >> d;

	if(r < b) {
		swap(r, b);
	}

	// if(check(r, b, d)) {
	// 	cout << "YES\n";
	// 	return;
	// }

	// int r1 = b - 1, r2 = r1 + d - 1;

	// if(!check(r1, r2, d)) {
	// 	cout << "NO\n";
	// 	return;
	// }

	// r -= r2, b -= r1;

	// // cerr << r << endl << b << endl;

	if(b * (d + 1) >= r) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
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
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}