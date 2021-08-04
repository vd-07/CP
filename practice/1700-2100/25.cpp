//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

const int N = (int)1e7 + 1;

int n;
int a[N], spf[N];

int process(int num) {
	int sum = 1;
	while(num > 1) {
		int currPrime = spf[num];
		int currNum = 1;
		int currSum = 1;
		while(num % currPrime == 0) {
			num /= currPrime;
			currNum *= currPrime;
			currSum += currNum;
		}
		sum *= currSum;
	}
	return sum;
}

void constructAnswer() {
	for(int i = 1; i <= N; ++ i) {
		spf[i] = i;
		a[i] = INT_MAX;
	}

	spf[1] = 1;
	for(int i = 2; i * i <= N; ++ i) {
		if(spf[i] == i) {
			for(int j = i * i; j <= N; j += i) {
				spf[j] = i;
			}
		}
	}

	a[1] = 1;
	for(int i = 2; i <= N; ++ i) {
		int sum = process(i);
		if(sum <= N) {
			a[sum] = min(a[sum], i);
		}
	}
}

void solve() {
	cin >> n;
	cout << (a[n] == INT_MAX ? -1 : a[n]) << "\n";
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

	constructAnswer();

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