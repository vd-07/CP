//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void solve() {
	cin >> n;

	map<int, vector<int>> mp;

	for(int i = 0; i < n; ++ i) {
		cin >> a[i];

		mp[a[i]].push_back(i);
	}

	int ans = 0;

	for(auto &v : mp) {
		int sum = 0;

		for(int i = v.second.size() - 1; i >= 0; -- i) {
			int id = v.second[i];

			ans += (id + 1) * sum;

			sum += n - id;
		}
	}

	cout << ans << "\n";
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