// https://codeforces.com/contest/1038/problem/D

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 10;

int n;
int a[N];

void solve() {
	cin >> n;

	int ctNegative = 0, ctPositive = 0;
	int minNum = 1e9;
	int sum = 0;

	for(int i = 0; i < n; ++ i) {
		cin >> a[i];

		ctNegative += (a[i] < 0);
		ctPositive += (a[i] > 0);

		minNum = min(minNum, abs(a[i]));
		sum += abs(a[i]);
	}

	if(n == 1) {
		cout << a[0];
		return;
	}
	
	if(ctNegative != n && ctPositive != n) {
		cout << sum;
	} else {
		cout << sum - 2 * minNum;
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