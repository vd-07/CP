// https://codeforces.com/problemset/problem/1436/C

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

int n, x, pos;

int factorial(int n) {
	return (n <= 1 ? 1 : (n * factorial(n - 1)) % mod);
}

void solve() {
	cin >> n >> x >> pos;

	int big = n - x, small = x - 1;
	int ans = 1;

	int l = 0, r = n;
	bool ok = true;

	while(l < r) {
		int mid = (l + r) / 2;

		if(mid == pos) {
			ok = false;
			l = mid + 1;
			continue;
		}

		if(mid < pos && ok) {
			l = mid + 1;
			ans *= (small--);
			ans %= mod;
		} else {
			r = mid;
			ans *= (big--);
			ans %= mod;
		}

		if(big < 0 || small < 0) {
			cout << "0";
			return;
		}
	}

	ans *= factorial(big + small);
	ans %= mod;

	cout << ans;
}

signed main() {
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int t = 1;
	// cin >> t;

	while(t--) {
		solve();
	}

	
	return 0;
}