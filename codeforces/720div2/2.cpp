//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;
int a[mxN];

void operation(int i, int j, int x, int y) {
	cout << i << " " << j << " " << x << " " << y << "\n";

	a[i] = x, a[j] = y;
}

void solve() {
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << n / 2 << "\n";
	for(int i = 1; i + 1 <= n; i += 2) {
		operation(i, i + 1, min(a[i], a[i + 1]), 1e9 + 7);
	}

	// for(int i = 1; i <= n; i++) {
	// 	cerr << a[i] << " ";
	// }
	
	// cerr << endl;
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