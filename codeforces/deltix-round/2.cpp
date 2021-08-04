//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;
int a[mxN];

void perform(int type, int i, int j) {
	cout << type << " " << i <<  " " << j << "\n";
	if(type == 1) {
		a[i] += a[j];
	} else {
		a[j] -= a[i];
	}
}
void solve() {
	cin >> n;

	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}

	cout << n * 3 << "\n";
	for(int i = 1; i <= n; i += 2) {
		perform(1, i, i + 1);
		perform(2, i, i + 1);
		perform(1, i, i + 1);
		perform(2, i, i + 1);
		perform(1, i, i + 1);
		perform(2, i, i + 1);
	}
	// for(int i = 1; i <= n; ++ i) {
	// 	cerr << a[i] << ' ';
	// }
	// cerr << "\n";

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