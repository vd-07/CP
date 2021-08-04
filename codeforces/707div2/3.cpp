//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

const int mxN = 3e5 + 1;

int n;

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

	cin >> n;

	vector<int> a(n);

	for(int i = 0; i < n; i++) {
		cin >> a[i];

	}

	vector<pair<int, int>> sp(5000001, {-1, -1});

	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			int sum = a[i] + a[j];

			if(sp[sum].first == -1) {
				sp[sum] = {i, j};
			} else {
				int x = sp[sum].first, y = sp[sum].second;

				if(x == i || x == j || y == i || y == j) {

				} else {
					cout << "YES\n";
					++x, ++y, ++i, ++j;
					cout << x << " " << y << " " << i << " " << j;
					return 0;
				}
			}
		}
	}

	cout << "NO\n";

	return 0;
}