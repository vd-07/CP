#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;
const int N = 2e5 + 10;

int n;
int a[N];

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

int solve() {
	cin >> n;

	int t1 = 0, t2 = 0, prev = 0;

	for(int i = 0; i < n; i++) {
		cin >> a[i];

		t1 += a[i] * a[i];

		t1 %= mod;
		
	}

	sort(a, a + n);

	prev = a[0];

	for(int i = 1; i < n; i++) {
		t2 += (prev * a[i]) % mod;
		t2 %= mod;

		prev *= 2;
		prev %= mod;

		prev += a[i];
		prev %= mod;
	}

	int ans = (t1 + t2) % mod;

	return ans;

}

signed main() {
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	cout << solve();

	return 0;
}