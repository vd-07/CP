//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];
bool ok = false;

void recur(int bitmask, int sum, int taken = 0) {
	if(ok) return;
	
	if(sum == 0 && taken) {
		// cerr << bitmask << endl;
		ok = true;
		return;	
	}
	for(int i = 0; i < n; ++ i) {
		if((bitmask & (1 << i)) == 0) {
			
			
			// haven't taken yet
			bitmask = (bitmask | (1 << i));
			recur(bitmask, sum + a[i], taken + 1);
			recur(bitmask, sum - a[i], taken + 1);
		}
	}
}

void solve() {
	cin >> n;

	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
	}

	set<int> s;

	for(int i = 0; i < (1 << n); ++ i) {
		int sum = 0;
		for(int id = 0; id < n; ++ id) {
			if(i & (1 << id)) {
				sum += a[id];
			}
		}
		if(s.count(sum)) {
			cout << "YES\n";
			return;
		}
		s.insert(sum);
	}
	cout << "NO\n";
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