// https://codeforces.com/contest/1515/problem/D
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, l, r;

void solve() {
	cin >> n >> l >> r;

	vector<int> colors(n + 1);

	for(int i = 0; i < l; i++) {
		int c;
		cin >> c;

		++ colors[c];
	}

	for(int i = 0; i < r; i++) {
		int c;
		cin >> c;

		-- colors[c];
	}

	int lc = 0, rc = 0;
	vector<int> l, r;

	for(int i = 1; i <= n; i++) {
		if(colors[i] < 0) {
			rc += -colors[i];
			r.push_back(-colors[i]);
		} else {
			lc += colors[i];
			l.push_back(colors[i]);
		}
	}

	if(lc < rc) {
		swap(lc, rc);
		swap(l, r);
	}

	int ans = 0;

	for(int v : l) {
		int reduced = v - (v % 2);

		if(lc - reduced < rc) {
			ans += (lc - rc) / 2 + rc;
			lc = 0;
			break;
		}

		lc -= reduced;

		ans += reduced / 2;
	}

	cout << ans + lc << "\n";
}

signed main() {
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	int t;

	cin >> t;

	while(t--) {
		solve();
	}

	
	return 0;
}