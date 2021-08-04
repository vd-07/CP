//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

#include <iostream>
#include <map>
using namespace std;

int substring_with_atmost_k_characters(string s , int k) {
	if ( k == 0) {
		return 0;
	}
	map<int, int> frequency;
	int n = s.length(); 
	int j = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		frequency[s[i]] ++;
		while ((int)frequency.size() > k and j <= i) {
			int p = frequency[s[j]]--;
			if (p == 1) {
				frequency.erase(s[j]);
			}
			j++;
		}
		if ((int)frequency.size() == k) {
			count += i - j - k + 2;
		}
	}
	return count;
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
	while (t--) {
		int k;
		string s;
		cin >> s >> k;
		cout << substring_with_atmost_k_characters(s, k) << "\n";
	}

#ifdef CODINGINVEINS
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

	return 0;
}