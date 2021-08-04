//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long 

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
	int a, b, c, d;
	while(t--) {
		cin >> a >> b >> c >> d;
		cout << max({a * c, a * d, b * c, b * d});
	}

	return 0;
}