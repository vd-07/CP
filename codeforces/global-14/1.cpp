//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void print() {
	cout << "YES\n";

	for(int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	cout << "\n";
}

bool check() {
	int sum = 0;

	for(int i = 0; i < n; i++) {
		sum += a[i];

		if(sum == k) {
			return false;
		}
	}

	return true;
}

void solve() {
	cin >> n >> k;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int sum = 0;

	for(int i = 0; i < n; i++) {
		sum += a[i];

		if(sum == k) {
			if(a[i] == a[n - 1]) {
				cout << "NO\n";
				return;
			}

			swap(a[i], a[n - 1]);
			break;
		}
	}
	print();
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