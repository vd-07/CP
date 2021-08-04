//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, q;
int a[mxN];

void solve() {
	cin >> n;

	map<int, int> result, nextDivisors, divisors;	

	for(int i = 0; i < n; ++ i) {
		int a;
		cin >> a;

		for(pair<int, int> p: divisors) {
			nextDivisors[__gcd(a, p.first)] += p.second;
		}

		++ nextDivisors[a];

		for(pair<int, int> p: nextDivisors) {
			result[p.first] += p.second;
		}

		divisors = nextDivisors;
		nextDivisors.clear();
	}

	cin >> q;

	while(q --) {
		int x;
		cin >> x;
		printf("%lld\n", result[x]);
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