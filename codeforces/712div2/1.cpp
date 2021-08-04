//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void solve() {
	string s;
	cin >> s;

	bool ok = false;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] != 'a') {
			ok = true;
			break;
		}
	}

	if(!ok) {
		cout << "NO\n";
		return;
	}

	int n = s.size();

	cout << "YES\n";
	for(int i = 0; i < n; i++) {
		if(s[n - i - 1] != 'a' && ok) {
			cout << 'a';
			ok = false;
		}
		cout << s[i];
	}
	cout << "\n";
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