//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;
int a[mxN], b[mxN], c[mxN], d[mxN];

map<pair<int, int>, set<int>> slopes;

vector<pair<array<int, 2>, set<int>>> edges[mxN];

bool cmp(pair<array<int, 2>, set<int>> &p1, pair<array<int, 2>, set<int>> &p2) {
	return p1.first[0] < p2.first[0];
}

void solve() {
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		int n1 = c[i] * b[i] + d[i] * b[i];
		int d1 = a[i] * d[i];

		slopes[{n1, d1}].insert(i);

		n1 = c[i] * b[i];
		d1 = a[i] * d[i] + b[i] * d[i];

		slopes[{n1, d1}].insert(i);
	}

	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		int n1 = c[i] * b[i] + d[i] * b[i];
		int d1 = a[i] * d[i];

		for(int v : slopes[{n1, d1}]) {
			if(v != i) {
				edges[i].second.insert(v);	
			}
		}

		n1 = c[i] * b[i];
		d1 = a[i] * d[i] + b[i] * d[i];

		for(int v : slopes[{n1, d1}]) {
			if(v != i) {
				edges[i].second.insert(v);	
			}
		}
		edges[i].first[0] = edges[i].second.size();
		edges[i].first[1] = i;
	}

	sort(edges.begin(), edges.end(), cmp);

	int ans = 0;

	vector<bool> visited(n + 1);

	for(auto a : edges) {
		int u = a.first[1];

		if(a.second.empty() || visited[u]) {
			continue;
		}

		for(int v : a.second) {
			if(visited[v] == false) {
				visited[v] = true;

				ans ++;		

				break;
			}
			
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
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}