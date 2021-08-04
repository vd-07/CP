//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;

void solve() {
	cin >> n;

	deque<int> ts;
	vector<int> ms;

	for(int i = 0; i < n; i++) {
		char c;
		cin >> c;

		if(c == 'T') {
			ts.push_back(i);
		} else {
			ms.push_back(i);
		}
	}

	bool ok = true;

	for(int i : ms) {
		if(ts.empty()) {
			ok = false;
			break;
		}
		int f = ts.front();
		if(f > i) {
			ok = false;
			break;
		}
		ts.pop_front();
	}

	reverse(ms.begin(), ms.end());


	for(int i : ms) {
		if(ts.empty() || ok == false) {
			ok = false;
			break;
		}
		int f = ts.back();
		if(f < i) {
			ok = false;
			break;
		}
		ts.pop_back();
	}	

	if(ts.empty() && ok) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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