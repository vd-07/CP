//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, p;
int a[mxN];

vector<bool> vis;

int calc(int i) {

	int l = i;

	// backwards

	for(int j = i - 1; j >= 0; j--) {
		if(vis[j + 1]) {
			break;
		}

		if(a[j] % a[i] == 0) {
			l = j;
		} else {
			break;
		}
		
	}

	// forward
	int r = i;

	for(int j = i + 1; j < n; j++) {
		if(vis[j - 1]) {
			break;
		}

		if(a[j] % a[i] == 0) {
			r = j;
		} else {
			break;
		}
	}

	for(int i = l; i <= r; i++) {
		vis[i] = true;
	}

	return r - l;
}

void solve() {
	cin >> n >> p;

	vector<pair<int, int>> small;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		small.push_back({a[i], i});
	}

	sort(small.begin(), small.end());
	vis = vector<bool> (n, false);

	int ans = 0;
	int dis = 0;

	for(pair<int, int> pa : small) {
		int v = pa.first, i = pa.second;
		if(vis[i]) {
			continue;
		}

		if(v >= p) {
			break;
		}
		
		int curr = calc(i);

		dis += curr;
		ans += curr * v;
	}
	// debug(vis);

	ans += (n - dis - 1) * p;

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
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}