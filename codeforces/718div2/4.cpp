//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e2 + 10;

int n, m, k;
vector<array<int, 3>> edge[N][N];
vector<vector<vector<int>>> dp(N, vector<vector<int>> (N, vector<int> (21, -1)));


int dfs(int i, int j, int k) {
	if(k == 0) {
		return 0;
	}

	if(dp[i][j][k] != -1) {
		return dp[i][j][k];
	}

	int curr = INT_MAX;

	for(auto v : edge[i][j]) {
		curr = min(curr, dfs(v[0], v[1], k - 1) + v[2]);
	}

	return dp[i][j][k] = curr;
}

void solve() {
	cin >> n >> m >> k;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < m; j++) {
			int weight;
			cin >> weight;

			edge[i][j].push_back({i, j + 1, weight});
			edge[i][j + 1].push_back({i, j, weight});
		}
	}

	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= m; j++) {
			int weight;
			cin >> weight;

			edge[i][j].push_back({i + 1, j, weight});
			edge[i + 1][j].push_back({i, j, weight});
		}
	}

	if(k % 2 == 1) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cout << "-1 ";
			}
			cout << "\n";
		}
		return;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			// cout << "vd";
			cout << 2 * dfs(i, j, k / 2) << " ";
			// cout << dp[i][j][k] << " ";
		}
		cout << "\n";
	}
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