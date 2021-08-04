//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;

void solve() {
	cin >> n;
	string s;

	cin >> s;

	int countZeros = 0;

	for(char c : s) {
		countZeros += (c == '0');
	}

	// cerr << countZeros;

	int a = 0, b = 0;

	// bool start = 0;

	// if(countZeros & 1) {
	// 	++ a;
	// 	-- countZeros;
	// 	start = 1;
	// }

	// while(countZeros) {
	// 	if(start) {
	// 		b += 2;
	// 	} else {
	// 		a += 2;
	// 	}
	// 	start ^= 1;
	// 	countZeros -= 2;
	// }

	if(countZeros == 1) {
		cout << "BOB\n";
	} else {
		if(countZeros & 1) {
			cout << "ALICE\n";
		} else {
			cout << "BOB\n";
		}
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