//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

// const int mxN = 3e5 + 1;

int n, a, b, c, d;
int x = 1, y = 1;

vector<string> land(52, string(102, '.'));

void reset(int s1, int e1, int s2, int e2) {
	for(int i = s1; i <= e1; i++) {
		for(int j = s2; j <= e2; j++) {
			land[i][j] = '#';
		}
	}
}

// bool nextCoordinate1() {
// 	if(land[x][y + 1] == '#') {
// 		++ y;
// 	} else if(land[x][y - 1] == '#') {
// 		-- y;
// 	} else if(land[x - 1][y] == '#') {
// 		-- x;
// 	} else if(land[x + 1][y] == '#') {
// 		++ x;
// 	} else {
// 		return false;
// 	}
// 	return true;
// }

// bool nextCoordinate2() {
// 	if(land[x][y - 1] == '#') {
// 		-- y;
// 	} else if(land[x + 1][y] == '#') {
// 		++ x;
// 	} else if(land[x][y + 1] == '#') {
// 		++ y;
// 	} else if(land[x - 1][y] == '#') {
// 		-- x;
// 	} else {
// 		return false;
// 	}
// 	return true;	
// }

void print() {
	for(int i = 1; i <= max(b, d); i++) {
		for(int j = 1; j <= a + c; j++) {
			cout << land[i][j];
		}
		cout << "\n";
	}
}

void refresh1() {
	for(int j = 1; j <= a + c; j++) {
		for(int i = 1; i <= max(b, d); i++) {
			if(land[i][j] == '#') {
				x = i, y = j;
				return;
			}
		}
	}
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool nextCoordinate1(char curr) {
	for(int j = 1; j <= a + c; j++) {
		for(int i = 1; i <= max(b, d); i++) {
			if(land[i][j] == '#') {
				for(int k = 0; k < 4; k++) {
					if(land[i + dx[k]][j + dy[k]] == curr) {
						x = i, y = j;
						return true;
					}
				}
			}
		}
	}	

	return false;	
}

bool nextCoordinate(char curr) {
	if(d > b) {
		return nextCoordinate1(curr);
	} 

	for(int i = 1; i <= max(b, d); i++) {
		for(int j = 1; j <= a + c; j++) {
			if(land[i][j] == '#') {
				for(int k = 0; k < 4; k++) {
					if(land[i + dx[k]][j + dy[k]] == curr) {
						x = i, y = j;
						return true;
					}
				}
			}
		}
	}	

	return false;
}

void refresh() {
	if(b < d) {
		refresh1();
		return;
	}
	
	for(int i = 1; i <= max(b, d); i++) {
		for(int j = 1; j <= a + c; j++) {
			if(land[i][j] == '#') {
				x = i, y = j;
				return;
			}
		}
	}	
}

void solve() {
	cin >> a >> b >> c >> d >> n;

	// reset(1, b, 1, a);

	// reset(1, d, 1 + a, a + c);

	vector<pair<int, int>> order;

	for(int i = 1; i <= a + c; ++ i) {
		if((i - a) % 2 == 0) {
			for(int j = (i <= a ? b : d); j >= 1; -- j) {
				order.push_back({j, i});
			}
		} else {
			for(int j = 1; j <= (i <= a ? b : d); ++ j) {
				order.push_back({j, i});
			}
		}
	}

	// reverse(order.begin(), order.end());

	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		while(x--) {
			land[order.back().first][order.back().second] = 'a' + i - 1;
			order.pop_back();
		}
	}

	cout << "YES\n";

	print();

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