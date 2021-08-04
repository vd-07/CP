//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 1e3 + 10;

int n;
int a[mxN];

void solve() {
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int cost = 0;

	for(int i = 0; i < n - 1; i++) {
		int j = i;
		for(int k = i; k < n; k++) {
			if(a[j] > a[k]) {
				j = k;
			}
		}

		cost += j - i + 1;

		reverse(a + i, a + j + 1);
		// for(int i = 0; i < n; i++) {
		// 	cerr << a[i] << " ";
		// }
		// cerr << endl;
	}

	cout << cost << "\n";
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
	int t;
    	cin >> t;
    	for(int i = 1; i <= t; i++) {
        cout << "Case #"<< i << ": ";
        solve();
    	}

	return 0;
}