//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m, x;
int height[mxN];

void solve() {
	cin >> n >> m >> x;

	set<pair<int, int>> s;

	cout << "YES\n";

	for(int i = 1; i <= m; i++) {
		s.insert({0, i});
	}

	for(int i = 0; i < n; i++) {
		cin >> height[i];

		pair<int, int> p = *s.begin();

		s.erase(s.begin());

		s.insert({p.first + height[i], p.second});

		cout << p.second << " ";
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