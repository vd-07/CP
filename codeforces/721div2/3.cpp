//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;

int process(int count) {
	if(count <= 1) {
		return count;
	}

	int a = count / 2;

	if(count % 2 == 0) {
		++ a;
	}

	return a;
}

void solve() {
	cin >> n;
	string s;

	cin >> s;

	int count01 = 0;
	int count00 = 0;

	for(int i = 0; 2 * i < s.size(); ++ i) {
		if(s[i] != s[n - i - 1]) {
			++ count01;
		}

		if(s[i] == s[n - i - 1] && s[i] == '0') {
			count00 += 2;
			if(i == n - i - 1) {
				-- count00;
			}
		}
	}

	// cerr << count01 << endl << count00 << endl;

	int b = count01;

	int a = process(count00);

	b += count00 - a;

	// cerr << a << endl << b << endl;

	if(a == b) {
		cout << "DRAW\n";
	} else if(a > b){
		cout << "BOB\n";
	} else {
		cout << "ALICE\n";
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