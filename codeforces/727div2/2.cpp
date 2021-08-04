//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, q;

void solve() {
	cin >> n >> q;
	string s;

	cin >> s;

	int freq[n][26] = {};

	for(int i = 0; i < n; ++ i) {
		++ freq[i][s[i] - 'a'];

		if(i == 0) {
			continue;
		}
		
		for(int j = 0; j < 26; ++ j) {
			freq[i][j] += freq[i - 1][j];
		}
	}

	while(q--) {
		int l, r;

		cin >> l >> r;
		-- l, -- r;

		// cerr << l << " " << r << endl;

		int ans = 0;

		for(int i = 0; i < 26; ++ i) {
			int ct = freq[r][i];
			if(l != 0) {
				ct -= freq[l - 1][i];
			}

			ans += ct * (i + 1);
		}

		cout << ans << "\n";
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