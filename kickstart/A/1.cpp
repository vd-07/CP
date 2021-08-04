//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;

void solve() {
	cin >> n >> k;

	string s(n + 1, '#');
	
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
	}

	for(int i = 1; i <= n / 2; i++) {
		if(s[i] != s[n - i + 1]) {
			k--;
		}
	}

	cout << (abs(k)) << "\n";
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