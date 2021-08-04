//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;
int a[mxN];
vector<pair<int, int>> b;
vector<vector<int>> dp;

int recur(int i, int j) {
	// fix from back
	// either i or j
	if(i > j) {
		return 0;
	}

	if(dp[i][j] != -1) {
		return dp[i][j];
	}
	int v1 = 0, v2 = 0;

	// choose i, which is the smallest
	// will react with the biggest just once???

	if(i != j) {
		// choose the smallest
		v1 = (b[j].first - b[i].first) * b[i].second;
		// choose the greatest
		v2 = (b[j].first - b[i].first) * b[j].second;
	}

	v1 += recur(i + 1, j);
	v2 += recur(i, j - 1);

	return dp[i][j] = min(v1, v2);
}

void solve() {
	cin >> n;

	map<int, int> mp;

	for(int i = 0; i < n; i++) {
		int e;
		cin >> e;
		mp[e] ++;
	}

	for(pair<int, int> p : mp) {
		b.push_back(p);
	}

	dp = vector<vector<int>> (b.size(), vector<int> (b.size(), -1));

	int ans = recur(0, (int)b.size() - 1);

	cout << ans;

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