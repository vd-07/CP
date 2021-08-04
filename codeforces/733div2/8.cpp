//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 4e5 + 10;
int n;
int a[mxN];
int sparseTable[mxN][51];

void buildSparseTable(int n) {
	for(int i = 0; i < n; ++ i) {
		sparseTable[i][0] = a[i];
	}
	 for (int j = 1; j <= 19; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            sparseTable[i][j] = __gcd(sparseTable[i][j - 1],
                    sparseTable[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int queryForGCD(int L, int R)
{
    int returnValue;

    int j = (int)(log2(R - L + 1));
     
    returnValue = __gcd(sparseTable[L][j],
                    sparseTable[R - (1 << j) + 1][j]);
                     
    return returnValue;
}

bool check(int steps, int g) {
	for(int i = 0; i < n; ++ i) {
		if(queryForGCD(i, i + steps) != g) {
			return false;
		}
	}
	return true;
}

int bs(int l, int r, int gcd) {
	int ans = n - 1;
	while(l <= r) {
		int mid = (l + r) / 2;

		if(check(mid, gcd)) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
		}
	}
	return ans;
}

void solve() {
	cin >> n;

	int gcd = 0;

	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
		gcd = __gcd(a[i], gcd);
	}

	for(int i = n; i < 2 * n; ++ i) {
		a[i] = a[i - n];
	}

	buildSparseTable(2 * n);

	int ans = bs(0, n - 1, gcd);
	cout << ans << "\n";
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
	cin >> t;
	while(t--) {
		solve();
	}

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}