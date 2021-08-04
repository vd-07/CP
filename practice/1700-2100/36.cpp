// Author : Vivek Dubey
// https://codeforces.com/problemset/problem/1503/B
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 1e2 + 10;

int n;
int mat[mxN][mxN];

int alice() {
	int a;
	cin >> a;
	return a;
}

bool notInNeighbour(int x, int y, int color) {
	for(int d: {-1, 1}) {
		if(mat[x + d][y] == color) return false;
		if(mat[x][y + d] == color) return false;
	}
	return true;
}

bool check(int b) {
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			if(mat[i][j] == 0 && notInNeighbour(i, j, b)) {
				mat[i][j] = b;
				cout << b << " " << i << " " << j << endl;
				return true;
			}
		}
	}
	return false;
}

void bob(int a) {
	for(int color: {1, 2, 3}) {
		if(color == a) {
			continue;
		}
		if(check(color)) break;
	}
}

void solve() {
	cin >> n;

	for(int i = 0; i < n * n; ++ i) {
		int a = alice();
		bob(a);
	}
}

int32_t main() {
	#ifdef CODINGINVEINS
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

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}