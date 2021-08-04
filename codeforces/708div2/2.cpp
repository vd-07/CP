//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m;
int a[mxN];

void solve() {
	cin >> n >> m;

	int mod[m] = {};

	for(int i = 0; i < n; i++) {
		int e;
		cin >> e;
		mod[e % m] ++;
	}

	int ans = (mod[0] > 0);

	for(int i = 1; 2 * i <= m; i++) {
		int b = mod[i];
		int s = mod[m - i];

		if(b < s) {
			swap(b, s);
		}

		if(b == s && b != 0) {
			ans ++;
			continue;
		} 

		ans += b - s;
	}

	cout << ans << "\n";
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