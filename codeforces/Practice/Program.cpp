//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m;
int val[mxN], preMin[mxN], preMax[mxN], suffMin[mxN], suffMax[mxN];

void solve() {
	cin >> n >> m;

	val[0] = 0;
	preMin[0] = 0, preMax[0] = 0;

	for(int i = 1; i <= n; i++) {
		char c;
		cin >> c;

		val[i] = (c == '+' ? 1 : -1);
		val[i] += val[i - 1];

		preMin[i] = min(val[i], preMin[i - 1]);
		preMax[i] = max(val[i], preMax[i - 1]);
	}

	suffMin[n] = val[n], suffMax[n] = val[n];

	for(int i = n - 1; i >= 1; --i) {
		suffMin[i] = min(suffMin[i + 1], val[i]);
		suffMax[i] = max(suffMax[i + 1], val[i]);
	}

	while(m--) {
		int l, r;
		cin >> l >> r;

		int m11 = preMin[l - 1], m12 = preMax[l - 1];

		// need to take care for r == n
		int m21 = m11, m22 = m12;

		if(r != n) {
			m21 = min(m21, suffMin[r + 1] - val[r] + val[l - 1]);
			m22 = max(m22, suffMax[r + 1] - val[r] + val[l - 1]);
		}

		cout << m22 - m21 + 1 << "\n";
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