//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void solve() {
	string s;
	cin >> s;

	vector<int> p, q;

	for(int i = 0; i + 1 < s.size(); ++ i) {
		if(s.substr(i, 2) == "AB") {
			p.push_back(i);
		}

		if(s.substr(i, 2) == "BA") {
			q.push_back(i);
		}
	}

	for(int i = 0; i < (int)q.size(); i += max(1, (int)q.size() - 1)) {
		for(int j = 0; j <  (int)p.size(); j += max(1, (int)p.size() - 1)) {
			if(abs(q[i] - p[j]) > 1) {
				cout << "YES";
				return;
			}
		}
	}

	cout << "NO\n";
	
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