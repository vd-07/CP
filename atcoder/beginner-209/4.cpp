//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, q;

vector<int> edges[mxN];
vector<int> dist(mxN);


void makeGraph() {
	cin >> n >> q;

	for(int i = 0; i < n - 1; ++ i) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
}

void findDist(int u, int p = 1, int depth = 0) {
	dist[u] = depth;

	for(int v : edges[u]) {
		if(v != p) {
			findDist(v, u, depth + 1);
		}
	}
}

void ansQueries() {
	while(q--) {
		int c, d;
		cin >> c >> d;

		int currDistance = abs(dist[c] + dist[d]);

		cout << (currDistance % 2 ? "Road" : "Town") << "\n";
	}
}

void solve() {
	makeGraph();
	findDist(1);
	ansQueries();
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

	while(t--) {
		solve();
	}

	return 0;
}