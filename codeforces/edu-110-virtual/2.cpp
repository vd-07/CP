//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;
int a[mxN];

void solve() {
	cin >> n;

	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
	}

	int j = n - 1;

	for(int i = 0; i < j; ) {
		if(a[i] & 1) {
			swap(a[i], a[j--]);
		} else {
			++ i;
		}
	}

	int count = 0;

	for(int i = 0; i < n; ++ i) {
		// cerr << a[i] << "\n";
		for(int j = i + 1; j < n; ++ j) {
			if(__gcd(a[i], 2 * a[j]) > 1) {
				++ count;
			}
		}
	}

	cout << count << "\n";
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