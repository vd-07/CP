//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;

int query(int i) {
	int ans;
	cout << "? " << i << endl;
	cin >> ans;
	return ans;
}

void solve() {
	cin >> n;

	int l = 1, r = n;

	while(l < r) {
		int mid = (l + r) / 2;
		int cmid = query(mid);
		int cmid1;
		if(mid + 1 > n) {
			cmid1 = n + 1;
		} else {
			cmid1 = query(mid + 1);
		}

		// always stay on the range l, r such that al < al - 1 && ar < ar + 1
		if(cmid > cmid1) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}

	cout << "! " << l << endl;
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
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}