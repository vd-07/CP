//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int t[4 * mxN];

int k;
string a;

void build(int v) {
    if (v < n) {
        t[v] = (a[tl] == '?' ? 2 : 1);
        build(2 * v);
        build()
    } 
}

void solve() {
	cin >> k;

	int n = (1 << k) - 1;

	cin >> a;

	build();

	int q;

	cin >> q;

	while(q--) {
		int p, c;

		cin >> p >> c;

		update

		print
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
	while(t--) {
		solve();
	}

	return 0;
}