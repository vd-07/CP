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

int calc(int num) {
	int count = 0;
	for(int i: primes) {
		if(num % i) continue;
		while(num % i == 0) {
			++ count;
			num /= i;
		}
	}

	return count + (num > 1);
}

string solve(int a, int b, int k) {
	int maxCount = calc(a) + calc(b);
	if(a < b) {
		swap(a, b);
	}

	if(a % b || a == b) {
		return (k >= 2 && maxCount >= k ? "YES\n" : "NO\n");
	} else {
		return (k >= 1 && maxCount >= k ? "YES\n" : "NO\n");
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

	sieve();

	// test cases
	int t = 1;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << solve(a, b, c);
	}

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}