//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e3 + 1;

int n, m;
int l[N][N];

void solve() {
	cin >> n >> m;

	vector<array<int, 3>> len;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> l[i][j];
			len.push_back({l[i][j], i, j});
		}
	}

	sort(len.begin(), len.end());

	vector<vector<int>> ans(n + 1, vector<int> (m + 1));

	for(int i = 0; i < m; i++) {
		int x = len[i][1], y = len[i][2];
		ans[x][y] = i + 1;
	}

	// form the answer;

	for(int i = 1; i <= n; i++) {
		vector<int> lrs, drs(m + 1);
		for(int j = 1; j <= m; j++) {
			if(ans[i][j]) {
				drs[ans[i][j]] = 1;
			}
		}

		for(int j = 1; j <= m; j++) {
			if(drs[j] == 0) {
				lrs.push_back(j);
			}
		}

		int k = 0;

		vector<int> runners(m + 1);
		for(int j = 1; j <= m; j++) {
			if(ans[i][j] == 0) {
				ans[i][j] = lrs[k++];
			}
			runners[ans[i][j]] = l[i][j];
		}

		for(int j = 1; j <= m; j++) {
			cout << runners[j] << " ";
		}
		cout << "\n";
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
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}