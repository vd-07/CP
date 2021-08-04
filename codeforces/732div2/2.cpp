//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m;

// source : https://cp-algorithms.com/string/string-hashing.html

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

void solve() {
	cin >> n >> m;

	string s;

	int freq[m][26] = {};

	for(int i = 0; i < n; ++ i) {
		cin >> s;

		for(int j = 0; j < m; ++ j) {
			++ freq[j][s[j] - 'a'];
		}
	}

	for(int i = 0; i < n - 1; ++ i) {
		cin >> s;
		for(int j = 0; j < m; ++ j) {
			-- freq[j][s[j] - 'a'];
		}
	}

	for(int j = 0; j < m; ++ j) {
		for(int k = 0; k < 26; ++ k) {
			if(freq[j][k]) {
				cout << char(k + 'a');
			}
		}
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

	return 0;
}