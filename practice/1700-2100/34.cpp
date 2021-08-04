//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m;
int a[mxN];

void solve() {
	cin >> n >> m;
	vector<array<int, 2>> edges[n + 1];
	for(int i = 0; i < m; ++ i) {
		int x, y, w;
		cin >> x >> y >> w;
		edges[x].push_back({y, w});
		edges[y].push_back({x, w});
	}

	vector<int> dist(n + 1, LLONG_MAX);
	priority_queue<array<int, 2>, vector<array<int, 2>>> q;
	vector<int> parent(n + 1);

	q.push({0, 1});
	dist[1] = 0;
	while(!q.empty()) {
		int u = q.top()[1];
		q.pop();
		for(array<int, 2> arr: edges[u]) {
			int v = arr[0], w = arr[1];
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				q.push({-w, v});
				parent[v] = u;
			}
		}
	}
	if(dist[n] == LLONG_MAX) {
		cout << "-1";
		return;
	}
	vector<int> path;
	int curr = n;
	while(curr != 1) {
		path.push_back(curr);
		curr = parent[curr];
	}
	path.push_back(1);
	reverse(path.begin(), path.end());

	for(int i: path) {
		cout << i << " ";
	}
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