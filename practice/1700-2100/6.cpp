// https://codeforces.com/contest/1521/problem/B#
#include <iostream>
using namespace std;

#define int long long

const int N = 2e5 + 10;

int n;
int a[N];

void solve() {
	cin >> n;

	int minElement = 1e9 + 1;
	int idx = -1;
	for(int i = 0; i < n; ++ i) {
		cin >> a[i];

		if(minElement > a[i]) {
			minElement = a[i];
			idx = i;
		}
	}

	cout << n - 1 << "\n";

	for(int i = 0; i < n; ++ i) {
		if(idx == i) {
			continue;
		}

		cout << idx + 1 << " " << i + 1 << " " << minElement << " " << (minElement + abs(i - idx)) << "\n";
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

	int t;
	cin >> t;

	while(t--) {
		solve();
	}

	
	return 0;
}