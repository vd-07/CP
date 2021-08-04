// https://atcoder.jp/contests/zone2021/tasks/zone2021_c
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e3 + 10;

int parameter[N][5];
vector<int> mask;
vector<vector<vector<int>>> dp;
int n;

void input() {
	cin >> n;

	for(int i = 0; i <= n; ++ i) {
		for(int j = 0; j < 5; ++ j) {
			cin >> parameter[i][j];
		}
	}
}

bool recur(int i, int currMask, int k) {
	if(k == 0) {
		return currMask == 31;
	}

	if(i == n) {
		return ((k == 0) ? (currMask == 31) : false);
	}

	if(dp[i][currMask][k] != -1) {
		return dp[i][currMask][k];
	}

	return dp[i][currMask][k] = (recur(i + 1, currMask, k) || 
					    recur(i + 1, currMask | mask[i], k - 1));
}

bool check(int x) {
	mask.assign(n, 0);

	// cerr << x << endl;

	for(int i = 0; i < n; ++ i) {
		int currMask = 0;

		for(int j = 0; j < 5; ++ j) {
			if(parameter[i][j] >= x) {
				currMask += (1 << j);
			}
		}

		mask[i] = currMask;

		// cerr << currMask << " ";
	}

	// cerr << endl;

	dp.assign(N, vector<vector<int>> (32, vector<int> (4, -1)));

	return recur(0, 0, 3);
}

int bs(int l, int r) {
	int ans = 1;

	while(l <= r) {
		int mid = (l + r) / 2;

		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	return ans;
}

signed main() {
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	input();

	cout << bs(1, 1e9);
	
	return 0;
}