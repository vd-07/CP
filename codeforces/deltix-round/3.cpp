//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;

void solve() {
	cin >> n;

	string s = "1";

	char c;
	cin >> c;
	-- n;

	int id = 0;

	while(n--) {
		// print
		for(int i = 0; i <= id; ++ i) {
			cout << s[i];
		}
		cout << "\n";

		cin >> c;

		if(c == '1') {
			if(s.size() < id + 2) {
				s += ".1";
			} else {
				s[id + 1] = '.';
				s[id + 2] = '1';
			}
			id += 2;
		} else {
			for(int i = id; i >= 0; -- i) {
				if(s[i] == '.') {
					continue;
				}
				int curr = s[i] - '0';
				if(curr + 1 == (c - '0')) {
					id = i;
					s[i] = c;
					break;
				}
			}
		}
	}

	for(int i = 0; i <= id; ++ i) {
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