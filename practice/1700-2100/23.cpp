//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int N = 3e6 + 1;
const int modulo = 998244353;
int spf[N];

void sieve() {
	for(int i = 1; i < N; ++ i) {
		spf[i] = i;
	}

	for(int i = 2; i * i < N; ++ i) {
		if(spf[i] == i) {
			for(int j = i * i; j < N; j += i) {
				spf[j] = i;
			}
		}
	}
}

int countDivisors(int n) {
	int count = 1;
	
	while(n > 1) {
		int currPrimeDivisor = spf[n];
		int c = 0;
		while(n % currPrimeDivisor == 0) {
			n /= currPrimeDivisor;
			++ c;
		}
		count *= c + 1;
	}

	return count;
}

void solve() {
	int n;
	cin >> n;

	int dp[n + 1];
	int prefixSum = 1;
	dp[1] = 1;

	for(int i = 2; i <= n; ++ i) {
		dp[i] = (countDivisors(i) + prefixSum) % modulo;
		prefixSum += dp[i];
	}

	cout << dp[n];
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
		sieve();
		solve();
	}

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}