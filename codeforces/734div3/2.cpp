//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void solve() {
	cin >> n >> k;

	map<int, vector<int>> freq;

	for(int i = 0; i < n; ++ i) {
		int a;
		cin >> a;
		freq[a].push_back(i);
	}

	int maxCols = 0;
	for(auto p:freq) {
		maxCols += min(k, (int)p.second.size());
	}
	maxCols /= k;

	int colors[n];
	int currCols = maxCols;

	for(auto p: freq) {
		int currSize = p.second.size();
		for(int i = 0; i < min(currSize, maxCols); ++ i) {
			if(currCols == 0) {
				currCols = maxCols;
			}
			colors[p.second[i]] = currCols--;
		}
		for(int i = k; i < currSize; ++ i) {
			colors[p.second[i]] = 0;
		}
	}

	for(int i = 0; i < n; ++ i) {
		cout << colors[i] << " ";
	}
	cout << "\n";
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
	cin >> t;
	while(t--) {
		solve();
	}

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}