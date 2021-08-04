// https://codeforces.com/contest/1529/problem/C

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;

int n;
int a[N][2];
vector<int> edges[N];
vector<vector<int>> dp;

int dfs(int u, int parent, int curr) {
	if(dp[u][curr] != -1) {
		return dp[u][curr];
	}

	int ans = 0;
	int currValue = a[u][curr];

	for(int v : edges[u]) {
		if(v != parent) {
			ans += max(abs(currValue - a[v][0]) + dfs(v, u, 0), abs(currValue - a[v][1]) + dfs(v, u, 1));
		}
	}
	return dp[u][curr] = ans;
}

void solve() {
	cin >> n;

	for(int i = 1; i <= n; ++ i) {
		cin >> a[i][0] >> a[i][1];
		edges[i].clear();
	}

	for(int i = 1; i < n; ++ i) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dp = vector<vector<int>> (n + 1, vector<int> (2, -1));

	int ans = max(dfs(1, 1, 0), dfs(1, 1, 1));

	cout << ans << '\n';
}

signed main() {
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int t = 1;
	cin >> t;

	while(t--) {
		solve();
	}

	
	return 0;
}