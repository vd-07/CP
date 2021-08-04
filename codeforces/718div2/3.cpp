//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e3 + 10;

int n;
int a[N][N] = {};

void solve() {
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i][i];
	}

	for(int i = 1; i <= n; i++) {
		int sx = i, sy = i;
		for(int i1 = 1; i1 < a[i][i]; i1++) {
			// first look for left
			if(sy - 1 >= 1 && a[sx][sy - 1] == 0) {
				sy -= 1;
			} else if(sx + 1 <= n && a[sx + 1][sy] == 0) {
				sx += 1;
			} else {
				cout << "-1";
				return;
			}
			a[sx][sy] = a[i][i];
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
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