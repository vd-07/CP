//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;
const int mod = 1e9 + 7;

int n, k;
int a[mxN];

int factorial(int k) {
	int ans = 1;

	for(int i = 2 ; i <= k; i++) {
		ans *= i;
		ans %= mod;
	}

	return ans;
}

void solve() {
	cin >> n;

	int ta = INT_MAX;
	for(int i = 0; i < n; i++) {
		cin >> a[i];

		ta = min(ta, a[i]);
	}

	int nota = 0;

	bool ok = false;

	for(int i = 0; i < n; i++) {
		if(ta == a[i]) {
			nota ++;
		}
		if((a[i] & ta) != ta) {
			ok = true;
		}
	}

	if(nota < 2 || ok) {
		cout << "0\n";
		return;
	}

	int ways = nota * (nota - 1);
	ways %= mod;

	ways *= (factorial(n - 2));

	ways %= mod;

	cout << ways << "\n";
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
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}