// https://codeforces.com/contest/349/problem/B
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 10;

int v;
int a[N];

void solve() {
	cin >> v;

	int minPaint = 1e5;
	int minDigit = -1;

	for(int i = 1; i <= 9; ++ i) {
		cin >> a[i];
		
		if(minPaint >= a[i]) {
			minPaint = a[i];
			minDigit = i;
		}
	}

	if(minPaint > v) {
		cout << "-1";
		return;
	}

	while(v >= minPaint) {
		int currentDigit = minDigit;

		int count = v / a[currentDigit];

		for(int i = 9; i >= 1; -- i) {
			if(v < a[i]) {
				continue;
			}
			
			int currentCount = (v - a[i]) / minPaint;

			if(currentCount + 1 == count) {
				currentDigit = i;
				break;
			}
		}

		cout << currentDigit;

		v -= a[currentDigit];
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