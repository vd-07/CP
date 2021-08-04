//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;
int a[mxN];

void solve() {
	cin >> n;

	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
	}

	int cnt = 0;
	vector<int> moves;

	while(!is_sorted(a, a + n)) {
		if(cnt & 1) {
			for(int i = 1; i < n - 1; i += 2) {
				if(a[i] > a[i + 1]) {
					moves.push_back(i + 1);
					swap(a[i], a[i + 1]);
					break;
				}
			}

			if(moves.size() == cnt) {
				if(n & 1) {
					swap(a[n - 2], a[n - 1]);
					moves.push_back(n - 1);	
				} else {
					swap(a[n - 3], a[n - 2]);
					moves.push_back(n - 2);
				}
			}

		} else {
			for(int i = 0; i < n - 1; i += 2) {
				if(a[i] > a[i + 1]) {
					moves.push_back(i + 1);
					swap(a[i], a[i + 1]);
					break;
				}
			}

			if(moves.size() == cnt) {
				if(n & 1) {
					swap(a[n - 3], a[n - 2]);
					moves.push_back(n - 2);	
				} else {
					swap(a[n - 2], a[n - 1]);
					moves.push_back(n - 1);
				}
			}
		}

		++ cnt;
	}

	cout << cnt << "\n";

	for(int i : moves) {
		cout << i << " ";
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