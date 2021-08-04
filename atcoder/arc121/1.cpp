//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;
map<pair<array<int, 3>, array<int, 3>>, bool> done;

int calc(array<int, 3> c1, array<int, 3> c2) {
	return max(abs(c1[0] - c2[0]), abs(c1[1] - c2[1]));
}

vector<int> process(vector<array<int, 3>> &x) {

	vector<int> ans;

	for(int i = 0; i < min(10ll, (int)x.size()); ++ i) {
		for(int j = n - 1; j >= max(0ll, n - 10) && i < j; -- j) {
			if(done[{x[i], x[j]}]) {
				continue;
			}

			done[{x[i], x[j]}] = true;

			ans.push_back(calc(x[i], x[j]));
		}
	}
	return ans;
}

void swapping(vector<array<int, 3>> &coordinates) {
	for(array<int, 3> &a : coordinates) {
		swap(a[0], a[1]);
	}
}

void solve() {
	cin >> n;

	vector<array<int, 3>> coordinates(n);

	for(int i = 0; i < n; ++ i) {
		cin >> coordinates[i][0] >> coordinates[i][1];
		coordinates[i][2] = i;
	}

	sort(coordinates.begin(), coordinates.end());

	vector<int> ans = process(coordinates);

	swapping(coordinates);

	sort(coordinates.begin(), coordinates.end());

	swapping(coordinates);

	vector<int> ans1 = process(coordinates);

	for(int i : ans1) {
		ans.push_back(i);
	}

	sort(ans.rbegin(), ans.rend());

	// for(int i : ans) {
	// 	cerr << i << endl;
	// }

	cout << ans[1];
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
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}