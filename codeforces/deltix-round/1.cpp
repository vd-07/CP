//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m;
string s;

bool check(int id) {
	int cnt = 0;

	if(id > 0) {
		if(s[id - 1] == '1') {
			++ cnt;
		}
	}

	if(id < n - 1) {
		if(s[id + 1] == '1') {
			++ cnt;
		}
	}

	return cnt == 1;
}

void fill(string &ans) {
	for(int i = 0; i < n; ++ i) {
		if(s[i] == '1') {
			for(int j = i + 1; j < n && (j - i) <= m; ++ j) {
				if(j < n - 1) {
					if(s[j + 1] == '1') {
						break;
					}
				}
				ans[j] = '1';
			}
		}
	}
}

void solve() {
	cin >> n >> m;

	
	cin >> s;

	int cnt = 0;

	while(cnt < m) {
		string newString = s;
		for(int i = 0; i < n; ++ i) {
			if(check(i)) {
				newString[i] = '1';
			}
		}

		if(newString == s) {
			break;
		}

		s = newString;

		++ cnt;
	}

	

	cout << s << "\n";
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