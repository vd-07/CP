//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;
int a[mxN];

int query(int t, int i, int j, int x) {
	cout << "? " << t << " " << i << " " << j << " " << x << endl;

	int ans;

	cin >> ans;

	return ans;
}

// 3 1 4 2

stack<int>

void process(int i) {
	int t2 = query(2, i, i + 1, 1);
	int t1 = query(1, i, i + 1, n - 1);

	if(t2 == 1) {
		a[i] = 1;
		// do something
	}

	if(t1 == n) {
		a[i + 1] = n;
	}

	int t3 = query(2, i + 1, i + 2, 1);
	int t4 = query(1, i + 1, i + 2, n - 1);

	if(t3 == 1) {
		a[i + 1] = 1;
	}

	if(t4 == n) {
		a[i + 2] = n;
	}

	if(t1 == t3) {
		a[i] = t2;
		a[i + 1] = t1;
		a[i + 2] = t4;
	} 

	if(t1 == t4) {
		a[i] = t2;
		a[i + 1] = t1;
		a[i + 2] = t3;
	}

	if(t2 == t3) {
		a[i] = t1;
		a[i + 1] = t2;
		a[i + 2] = t4;
	}

	if(t2 == t4) {
		a[i] = t1;
		a[i + 1] = t2;
		a[i + 2] = t3;	
	}
}

void print() {
	for(int i = 1; i <= n; ++ i) {
		cerr << a[i] << " ";
	}
	cerr << endl;
}

void solve() {
	cin >> n;

	for(int i = 1; i + 2 <= n; i += 3) {
		process(i);
	}	

	process(n - 2);

	cout << "! ";

	for(int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}

	cout << endl;
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