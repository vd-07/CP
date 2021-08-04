//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;
const int MAXN = 2e7 + 10;

int ndv[MAXN];

void sieve() {
	for(int i = 1; i < MAXN; i++) {
		ndv[i] = 0;
	}

	for(int i = 2; i < MAXN; i++) {
		if(ndv[i] == 0) {
			++ ndv[i];
			for(int j = 2 * i; j < MAXN; j += i) {
				++ ndv[j];
			}
		}
	}
}

int c, d, x;

int process(int n) {

	int ans = ndv[n];
	return (1 << ans);
}

void solve() {
	cin >> c >> d >> x;

	vector<int> g;

	for(int i = 1; i * i <= x; i++) {
		if(x % i) {
			continue;
		}

		g.push_back(i);

		if(i * i != x) {
			g.push_back(x / i);
		}
	}

	int ans = 0;

	for(int i : g) {
		if((x / i + d) % c) {
			continue;
		}
		
		int l = (x / i + d) / c;
		// cerr << i << " " << l << endl;
		ans += process(l);
	}
	cout << ans << "\n";
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

	sieve();

	// test cases
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}