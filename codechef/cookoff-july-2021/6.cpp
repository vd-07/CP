//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

set<int> dfs(int u, int p, vector<int> &ans, vector<vector<int>> &edges, vector<int> &C) {
	set<int> s;
	for(int v: edges) {
		if(v != p) {
			set<int> temp = dfs(v, u, ans, edges, C);
			s.insert(temp.begin(), temp.end());
		}
	}

	s.insert(C[u]);

	int mex = 0;

	while(mex < ans.size()) {
		if(s.count(i)) {
			++ mex;
		} else {
			ans[u] = mex;
			break;
		}
	}

	return s;
}

void solve(vector<int> &A, vector<vector<int>> &B, vector<int> C) {
	vector<vector<int>> edges(A + 1);

	for(vector<int> v: B) {
		edges[v[0]].push_back(v[1]);
		edges[v[1]].push_back(v[0]);
	}

	vector<int> ans(A);

	dfs(0, 0, ans, edges, C);
	
	// for(int i: ans) {
	// 	cout << i << " ";
	// }

	return ans;
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