// https://codeforces.com/contest/1038/problem/D

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;

int n;
int a[N], b[N];

bool sameSign(int a, int b) {
	return ((a > 0) == (b > 0));
}

void solve() {
	cin >> n;

	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
	}

	map<pair<int, int>, int> count;
	int anything = 0;

	for(int i = 0; i < n; ++ i) {
		cin >> b[i];

		if(a[i] == 0 && b[i] == 0) {
			anything ++;
			continue;
		}

		if(a[i] == 0) {
			continue;
		}

		if(b[i] == 0) {
			count[{0, 0}] ++;
			continue;
		}

		int gcd;

		if(sameSign(a[i], b[i])) {
			a[i] = abs(a[i]), b[i] = abs(b[i]);

			gcd = __gcd(a[i], b[i]);

			a[i] /= gcd;
			b[i] /= gcd;

			a[i] *= -1;
		} else {
			a[i] = abs(a[i]), b[i] = abs(b[i]);

			gcd = __gcd(a[i], b[i]);

			a[i] /= gcd;
			b[i] /= gcd;
		}

		count[{a[i], b[i]}] ++;
	}

	int ans = 0;

	for(auto v : count) {
		ans = max(ans, v.second);
	}

	cout << ans + anything;
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