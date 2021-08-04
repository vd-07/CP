//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e3 + 10;

int r, c;
int a[N][N];

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void solve() {
	cin >> r >> c;

	priority_queue<array<int, 3>> pq;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> a[i][j];
			pq.push({a[i][j], i, j});
		}
	}

	vector<vector<bool>> vis(r, vector<bool> (c, false));

	int ans = 0;

	while(!pq.empty()) {
		while((!pq.empty()) && vis[pq.top()[1]][pq.top()[2]]) {
			pq.pop();
		}

		if(pq.empty()) {
			break;
		}

		int x = pq.top()[1], y = pq.top()[2], cost = pq.top()[0];

		vis[x][y] = true;
		pq.pop();
		// cerr << x << " " << y << endl;
		// cerr << pq.size() << endl;

		for(int i = 0; i < 4; i++) {
			int nx = dx[i] + x, ny = dy[i] + y;
			if(nx >= 0 && ny >= 0 && nx < r && ny < c && (!vis[nx][ny])) {
				if(cost != a[nx][ny]) {
					ans += cost - a[nx][ny] - 1;
					a[nx][ny] = cost - 1;	
					pq.push({a[nx][ny], nx, ny});
				}
			}
		}
	}

	cout << ans << "\n";
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