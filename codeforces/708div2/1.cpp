//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void solve() {
	cin >> n;
	int f[101] = {};
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]] ++;
	}
	for(int i = 0; i <= 100; i++) {
		if(f[i]) {
			cout << i << ' ';
			f[i] --;
		}
	}

	for(int i = 0; i <= 100; i++) {
		while(f[i]) {
			cout << i << ' ';
			f[i] --;
		}
	}

	cout << "\n";
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