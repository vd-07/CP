//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k1, k2;
int w, b;

bool process(int k1, int k2, int w) {
	if(k1 < k2) {
		swap(k1, k2);
	}

	int v = k2;

	k1 -= k2;

	int h = k1 / 2;

	return v + h >= w;
}

void solve() {
	cin >> n >> k1 >> k2;
	cin >> w >> b;

	if(process(k1, k2, w) && process(n - k1, n - k2, b)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
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