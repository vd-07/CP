//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void solve() {
	cin >> n;

	int xorAll = 0;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		xorAll ^= a[i];
		// cerr << xorAll << endl;
	}

	// cerr << xorAll << endl;

	if(xorAll == 0) {
		cout << "YES\n";
		return;
	}

	int currXor = 0;

	int count = 0;

	for(int i = 0; i < n; i++) {
		currXor ^= a[i];

		if(currXor == xorAll) {
			// cerr << i << endl;
			currXor = 0;
			++ count;
		}
	}

	// cerr << count << endl;

	if((currXor == 0 || currXor == xorAll) && count > 1) {
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