//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void solve() {
	cin >> n >> k;

	int d1 = 0;

	for(int i = 1; i <= n; i++) {
		int curr = i * n * n;

		if(curr >= k) {
			d1 = i;	
			cout << d1 << " ";
			break;
		}
	}

	int d2 = 0;

	for(int i = 1; i <= n; i++) {
		int curr = (d1 - 1) * n * n + (1 * i * n);

		if(curr >= k) {
			d2 = i;
			cout << d2 << " ";
			break;
		}
	}

	int d3 = 0;

	for(int i = 1; i <= n; ++ i) {
		int curr = (d1 - 1) * n * n + (1 * (d2 - 1) * n) + i;

		if(curr >= k) {
			cout << i;
			break;
		}
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
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}