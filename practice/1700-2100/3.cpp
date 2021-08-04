// https://atcoder.jp/contests/arc116/tasks/arc116_c
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;
const int N = 2e5 + 200;

int n, m;
int factorial[N], invfac[N];

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

int nCr(int n, int r) {
	int num = factorial[n];
	int den = invfac[n - r] * invfac[r];
	den %= mod;

	int ans = (num * den) % mod;

	return ans;
}

int solve() {
	cin >> n >> m;

	int ans = 0;

	for(int i = 1; i <= m; i++) {
		int curr = 1;

		int num = i;

		for(int j = 2; j * j <= num; ++ j) {
			int count = 0;
			while(num % j == 0) {
				num /= j;
				++ count;
			}

			curr *= nCr(n + count - 1, count);
			curr %= mod;
		}

		if(num > 1) {
			curr *= n;
			curr %= mod;
		}

		ans += curr;
		ans %= mod;
	}

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

	factorial[0] = 1;

	for(int i = 1; i < N; i++) {
		factorial[i] = factorial[i - 1]  * i;
		factorial[i] %= mod;
	}

	invfac[N - 1] = modInverse(factorial[N - 1]) % mod;

	for(int i = N - 2; i >= 0; -- i) {
		invfac[i] = invfac[i + 1] * (i + 1);
		invfac[i] %= mod;
	}

	cout << solve();

	return 0;
}