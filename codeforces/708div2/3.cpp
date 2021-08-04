//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;

void solve() {
	cin >> n >> k;

	while(k > 3) {
		cout << 1 << " ";
		n--;
		k--;
	}

	if(n % 2 == 0) {
		if(n % 4 == 0) {
			cout << n / 2 << " " << n / 4 << " " << n / 4;
		} else {
			cout << (n - 2) / 2 << " " << (n - 2 ) / 2 << " " << 2;
		}
	} else {
		cout << 1 << " " << (n - 1) / 2 << " " << (n - 1) / 2;
	}
	cout << "\n";
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