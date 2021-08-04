// https://codeforces.com/contest/1396/problem/B

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e2 + 10;

int n;
int a[N];

void solve() {
	cin >> n;

	int sum = 0;
	for(int i = 0; i < n; ++ i) {
		cin >> a[i];

		sum += a[i];
	}

	for(int i = 0; i < n; ++ i) {
		if(2 * a[i] > sum) {
			cout << "T\n";
			return;
		}
	}

	if(sum & 1) {
		cout << "T\n";
	} else {
		cout << "HL\n";
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
	cin >> t;

	while(t--) {
		solve();
	}

	
	return 0;
}