// https://codeforces.com/problemset/problem/1426/E
// Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;

int wins(vector<int> a, vector<int> b) {
	int result = 0;
	// wins
	for(int i = 0; i < 3; ++ i) {
		int alice = i, bob = (i + 1) % 3;
		int temp = min(a[alice], b[bob]);
		result += temp;
	}

	return result;
}

void perform(vector<int> &a, vector<int> &b, int i, int type) {
	if(type) {
		// draw
		int temp = min(a[i], b[i]);
		a[i] -= temp;
		b[i] -= temp;
	} else {
		// loss
		int alice = i, bob = (i + 2) % 3;
		int temp = min(a[alice], b[bob]);
		a[alice] -= temp;
		b[bob] -= temp;
	}
}

int calcWins(vector<int> a, vector<int> b) {
	vector<pair<int, int>> curr;
	for(int i = 0; i < 3; ++ i) {
		curr.push_back({i, 0});
		curr.push_back({i, 1});
	}

	int ans = 1e9;

	do {
		vector<int> curra = a, currb = b;
		for(pair<int, int> op: curr) {
			int i = op.first, type = op.second;
			perform(curra, currb, i, type);
		}
		ans = min(ans, wins(curra, currb));
	} while(next_permutation(curr.begin(), curr.end()));

	return ans;
}

void solve() {
	cin >> n;

	vector<int> a(3), b(3);

	for(int i = 0; i < 3; ++ i) {
		cin >> a[i];
	}
	for(int i = 0; i < 3; ++ i) {
		cin >> b[i];
	}

	int maxWins = wins(a, b);
	int minWins = calcWins(a, b);

	cout << minWins << " " << maxWins << "\n";
}

int32_t main() {
	#ifdef CODINGINVEINS
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

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}