//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

bool comp(pair<int, int> p1, pair<int, int> p2) {
	if(p1.second == p2.second) {
		return p1.first < p2.first;
	}

	return p1.second < p2.second;
}

void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	for(int i = 0; i < n; ++ i) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), comp);

	for(pair<int, int> p : v) {
		cout << p.first << " " << p.second << "\n";
	}
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

l1 = input()

[n, k, p] = list(map(int, arr.split(' ')))

l2 = input()
arr = list(map(int,arr.split(' ')))

find_maximised_minimum(arr, n, p, k)