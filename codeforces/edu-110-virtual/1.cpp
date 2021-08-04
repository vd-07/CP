//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int s[4];
int a[mxN];

void solve() {
	for(int i = 0; i < 4; ++ i) {
		cin >> s[i];
	}

	int t[2];

	t[0] = max(s[0], s[1]);
	t[1] = max(s[2], s[3]);

	sort(s, s + 4);
	sort(t, t + 2);

	if(s[3] == t[1] && s[2] == t[0]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

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