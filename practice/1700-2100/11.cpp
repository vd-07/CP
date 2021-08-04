// https://codeforces.com/contest/1328/problem/D

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;

int n;
int a[N];
map<int, vector<int>> edges;
map<int, bool> visited;
map<int, int> ans;

void makeEdge(int u, int v) {
	edges[u].push_back(v);
	edges[v].push_back(u);
}

int findMex(vector<int> v) {
	
	vector<int> colors;

	for(int i : v) {
		colors.push_back(ans[i]);
	}

	sort(colors.begin(), colors.end());

	int mex = 1;

	for(int c : colors) {
		if(mex == c) {
			++ mex;
		}
	}

	return mex;
}

void solve() {
	cin >> n;

	// edges.clear();
	// visited.clear();
	// ans.clear();
	bool ok = true;

	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		if(i > 1 && a[i] != a[i - 1]) {
			ok = false;
		}
	}

	// a[0] = a[n], a[n + 1] = a[1];

	if(ok) {
		cout << "1\n";
		for(int i = 1; i <= n; ++ i) {
			cout << "1 ";
		}
		cout << "\n";
		return;
	}

	vector<int> color(n + 1);

	color[1] = 1;
	for(int i = 2; i <= n; ++ i) {
		// makeEdge(a[i], a[i - 1]);
		// makeEdge(a[i], a[i + 1]);
		color[i] = (color[i - 1]) % 2 + 1;

		if(ok == false && (n & 1) && a[i] == a[i - 1]) {
			color[i] = color[i - 1];
			ok = true;
		}

	}

	int k = 2;

	if(color[n] == color[1] && a[n] != a[1]) {
		color[n] = 3;
		++ k;
	}

	// cout << k << ""
	// for(int i = 1; i <= n; ++ i) {
	// 	if(ans[a[i]] != 0) {
	// 		continue;
	// 	}

	// 	int curr = findMex(edges[a[i]]);

	// 	ans[a[i]] = curr;

	// 	k = max(k, curr);
	// }

	cout << k << "\n";

	for(int i = 1; i <= n; ++ i) {
		cout << color[i] << " ";
	}

	cout << "\n";
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