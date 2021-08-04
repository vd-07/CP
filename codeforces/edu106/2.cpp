//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

string s;

void solve() {
	cin >> s;
	int fc = s.size();

	for(int i = 1; i < s.size(); i++) {
		if(s[i] == '1' && s[i - 1] == '1') {
			fc = i;
			break;
		}
	}

	for(int i = fc; i < s.size(); i++) {
		if(s[i] == '0' && s[i - 1] == '0') {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
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