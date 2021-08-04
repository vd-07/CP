// https://codeforces.com/contest/1359/problem/C

#include <bits/stdc++.h>
using namespace std;

#define int long long

int h, c, t;

int calc(int n1, int k) {
	return abs(n1 - t * k);
}

void solve() {

	cin >> h >> c >> t;

	if(h + c >= 2 * t) {
		cout << "2\n";
		return;
	}

	int k = (h - t) / (2 * t - h - c);

	int n1 = (k + 1) * h + (k * c);
	int n2 = (k + 2) * h + (k + 1) * c;

	if(calc(n1, 2 * k + 1) * (2 * k + 3) <= calc(n2, 2 * k + 3) * (2 * k + 1)) {
		cout << 2 * k + 1 << "\n";
	} else {
		cout << 2 * k + 3 << "\n";
	}
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
	cin >> t;

	while(t--) {
		solve();
	}

	
	return 0;
}