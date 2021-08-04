//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m, p;
int a[mxN][70];
vector<int> curr;

void recur(int i, vector<int> &friends, vector<int> &currency) {
	if(i >= m || currency.size() >= p) {
		if(currency.size() > curr.size()) {
			curr = currency;
		}
		return;
	}
	//dont select
	recur(i + 1, friends, currency);
	// select
	int cnt = 0;

	vector<int> newFriends;

	for(int j = 0; j < friends.size(); ++ j) {
		if(a[friends[j]][i]) {
			++ cnt;
			newFriends.push_back(friends[j]);
		}
	}

	if(cnt >= (n + 1) / 2) {
		currency.push_back(i);
		recur(i + 1, newFriends, currency);
		currency.pop_back();
	}
}

void solve() {
	cin >> n >> m >> p;

	vector<int> friends;
	vector<int> currency;

	for(int i = 0; i < n; ++ i) {
		friends.push_back(i);
		for(int j = 0; j < m; ++ j) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	}

	recur(0, friends, currency);

	map<int, int> present;

	for(int i : curr) {
		present[i] = 1;
	}

	for(int i = 0; i < m; ++ i) {
		cout << present[i];
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