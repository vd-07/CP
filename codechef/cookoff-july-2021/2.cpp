//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

void solve() {
	cin >> n;

	map<int, int> f;
	for(int i = 0; i < n; ++ i) {
		int a;
		cin >> a;
		++ f[a];
	}

	vector<pair<int, int>> freq;
	for(pair<int, int> p: f) {
		freq.push_back(p);
	}

	vector<int> pref(freq.size()), suff(freq.size());

	for(int i = 0; i < (int)freq.size(); ++ i) {
		pref[i] = (freq[i].first - 1) / 2;
		if(i > 0) {
			pref[i] = min(pref[i], pref[i - 1]);
		}
	}

	for(int i = (int)freq.size() - 1; i >= 0; -- i) {
		suff[i] = (freq[i].first - 1) / 2;
		if(i + 1 < (int)freq.size()) {
			suff[i] = min(suff[i], suff[i + 1]);
		}
	}

	int ans = n;

	for(int i = 0; i < (int)freq.size(); ++ i) {
		int curr = INT_MAX;
		if(i > 0) {
			curr = pref[i - 1];
		}
		if(i + 1 < (int)freq.size()) {
			curr = min(curr, suff[i + 1]);
		}

		if(curr >= freq[i].first) {
			ans = min(ans, n - freq[i].second);
		}
	}
	cout << ans << "\n";
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