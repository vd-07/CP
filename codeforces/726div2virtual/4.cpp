//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

vector<int> primes;
const int N = 32000;

void sieve() {
	bool mark[N] = {};

	for(int i = 2; i * i < N; ++ i) {
		if(!mark[i]) {
			for(int j = i * i; j < N; j += i) {
				mark[j] = true;
			}
		}
	}

	for(int i = 2; i < N; ++ i) {
		if(!mark[i]) {
			primes.push_back(i);
		}
	}
	// cerr << primes.size();
}

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void solve() {
	cin >> n;

	int count = 0;

	while(n % 2 == 0) {
		++ count;
		n /= 2;
	}

	if(count > 0 && (n > 1 || (count % 2 == 0))) {
		cout << "Alice\n";
	} else {
		cout << "Bob\n";
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
	cin >> t;
	while(t--) {
		solve();
	}

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}