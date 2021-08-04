//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;
vector<array<int, 2>> a;

bool check(int i) {
	int curr = a[i][1];
	for(int p = i; p <= a[i][1]; ++ p) {
		// cerr << p << endl;
		// cerr << curr << "" 
		if(a[p][1] == curr--) {
			continue;
		}
		return false;
	}
	return true;
}

void solve() {
	cin >> n;
	a = vector<array<int, 2>> (n);

	for(int i = 0; i < n; ++ i) {
		cin >> a[i][0], a[i][1] = i;
	}

	sort(a.begin(), a.end());

	int count = 0;
	int l = 0, r = 0;
	for(int i = 0; i < n; ++ i) {
		if(a[i][1] != i) {
			++ count;
			l = i, r = a[i][1];
			if(check(i) == false) {
				cout << "no";
				return;
			}
			i = r;
		}
	}

	if(count > 1) {
		cout << "no";
	} else {
		cout << "yes\n";
		cout << l + 1 << " " << r + 1;
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