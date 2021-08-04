//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN], b[mxN], c[mxN];

void solve() {
	
	cin >> n;

	int count[n + 1] = {};

	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		count[a[i]] ++;
	}

	for(int i = 1; i <= n; ++ i) {
		cin >> b[i];
	}

	int ans = 0;

	for(int i = 1; i <= n; ++ i) {
		cin >> c[i];

		int curr = b[c[i]];

		ans += count[curr];
	}

	cout << ans;

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