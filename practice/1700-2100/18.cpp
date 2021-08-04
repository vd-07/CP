// https://codeforces.com/contest/1038/problem/D

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;

int n;
int a[N];

void solve() {
	cin >> n;

	deque<int> q;

	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
		q.push_back(a[i]);
	}

	string ans = "";
	int last = 0;

	while(!q.empty()) {
		if(q.size() == 1) {
			if(q.front() > last) {
				ans += "L";
			}
			break;
		}

		if(q.front() == last && q.back() == last)

		if(q.front() > last && q.front() <= q.back())
	}

}

signed main() {
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int t = 1;
	// cin >> t;

	while(t--) {
		solve();
	}

	
	return 0;
}