//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e3 + 10;

int n;
int c[N], r[N], b[N][N];


bool check(vector<vector<int>> &a) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == -1) {
				return false;
			}
		}
	}

	return true;
}

int process(vector<vector<int>> &a) {
	int changed = 0;
	for(int i = 0; i < n; i++) {
		int x = 0;
		int ct = 0;
		int col;
		for(int j = 0; j < n; j++) {
			if(a[i][j] == -1) {
				ct ++;
				col = j;
			} else {
				x ^= a[i][j];
			}
		}

		if(ct == 1) {
			changed ++;
			a[i][col] = x ^ r[i];
		}	
	}

	for(int i = 0; i < n; i++) {
		int x = 0;
		int ct = 0;
		int row;
		for(int j = 0; j < n; j++) {
			if(a[j][i] == -1) {
				ct ++;
				row = j;
			} else {
				x ^= a[j][i];
			}
		}

		if(ct == 1) {
			changed ++;
			a[row][i] = x ^ c[i];
		}	
	}	
	// cerr << changed << endl;

	return changed;
}

pair<int, int> calc(vector<vector<int>> &a) {
	int wt = 10000, x = -1, y = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == -1) {
				if(b[i][j] < wt) {
					wt = b[i][j];
					x = i, y = j;
				}
			}
		}
	}
	// if(x == -1) {
	// 	return 0;
	// }
	return {x, y};
}

int recur(vector<vector<int>> a) {
	if(check(a)) {
		return 0;
	}
	// cerr << "vd";
	while(process(a));
	// cerr << "vd";

	if(check(a)) {
		return 0;
	}

	auto [x, y] = calc(a);

	a[x][y] = 0;

	int c1 = recur(a);

	a[x][y] = 1;

	int c2 = recur(a);

	// cerr << c1 << endl << c2 << endl;

	return min(c1, c2) + b[x][y];
}

void solve() {
	cin >> n;

	vector<vector<int>> a(n, vector<int> (n));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		cin >> r[i];
	}

	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}

	int cost = recur(a);

	cout << cost << "\n";
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
	int t;
    	cin >> t;
    	for(int i = 1; i <= t; i++) {
        cout << "Case #"<< i << ": ";
        solve();
    	}

	return 0;
}