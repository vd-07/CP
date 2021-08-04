//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;
const int mod = 998244353;

int n;
int a[mxN];

int power(int base, int expo) {
	int res = 1;
	while(expo) {
		if(expo & 1) {
			res = (res * base) % mod;
		}
		base = (base * base) % mod;
		expo /= 2;
	}
	return res;
}

int modInverse(int num) {
	return power(num, mod - 2);
}

void solve() {
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int res = a[0] * a[0];
	int ans = res % mod;;

	for(int i = 1; i < n; i++) {
		res = (res) * modInverse(a[i - 1]);
		res %= mod;

		res *= a[i];
		res %= mod;

		res += res - (a[i] * a[i - 1]) % mod;
		res = (res + mod) % mod;

		res += (a[i] * a[i]) % mod;
		res %= mod;
		// cerr << res << endl;
		ans += res;
		ans %= mod;
	}

	cout << ans;
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
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}