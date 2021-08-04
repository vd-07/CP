//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m;
int a[mxN];

void solve() {
	cin >> n >> m;

	vector<int> ans(m);

	vector<vector<int>> days(m), friends(n + 1);

	for(int i = 0; i < m; i++) {
		int k;
		cin >> k;

		int f;
		cin >> f;

		ans[i] = f;
		friends[f].push_back(i);

		days[i].push_back(f);

		for(int j = 1; j < k; j++) {
			cin >> f;
			days[i].push_back(f);
		}
	}

	for(int i = 1; i <= n; i++) {
		if(friends[i].size() > (m + 1) / 2) {
			int cnt = friends[i].size();
			for(int j = 0; j < friends[i].size() && cnt > (m + 1) / 2; j++) {
				if(days[friends[i][j]].size() < 2) {
					continue;
				}
				int nextFriend = days[friends[i][j]][1];
				ans[friends[i][j]] = nextFriend;

				-- cnt;
			}
			if(cnt > (m + 1) / 2) {
				cout << "NO\n";
				return;
			}
			break;
		}
	}

	cout << "YES\n";
	for(int i : ans) {
		cout << i << " ";
	}
	cout << "\n";
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
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}