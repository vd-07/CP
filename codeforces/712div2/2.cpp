//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 100;

int n, k;
int p[mxN];

bool isEqual(char a, char b, int inverted) {
	return ((a == b) ^ inverted);
}

void solve() {
	string a, b;

	cin >> n;
	cin >> a >> b;

	p[0] = (a[0] == '1' ? 1 : -1);

	for(int i = 1; i < a.size(); i++) {
		p[i] = (a[i] == '1' ? 1 : -1);

		p[i] += p[i - 1];
	}

	int inverted = 0;
	for(int i = (int)a.size() - 1; i >= 0; i--) {
		if(isEqual(a[i], b[i], inverted)) {
			continue;
		}

		if(p[i] == 0) {
			inverted ^= 1;
			continue;
		}

		cout << "NO\n";
		return;
	}

	cout << "YES\n";
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