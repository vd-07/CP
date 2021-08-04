// https://codeforces.com/contest/1521/problem/C
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e4 + 10;

int n;
int a[N];

int query(int t, int i, int j, int x) {
	cout << "? " << t << " " << i << " " << j << " " <<  x << endl;

	int ans;

	cin >> ans;

	return ans;
}

void solve() {
	cin >> n;

	int idx = -1;

	for(int i = 1; i + 1 <= n; i += 2) {
		int ans = query(1, i, i + 1, n - 1);

		if(ans == n) {
			idx = i + 1;
			break;
		}

		if(ans == n - 1) {
			ans = query(1, i + 1, i, n - 1);

			if(ans == n) {
				idx = i;
				break;
			}
		}
	}

	if(idx == -1) {
		idx = n;
	}

	a[idx] = n;

	for(int i = 1; i <= n; ++ i) {
		if(i != idx) {
			a[i] = query(2, i, idx, 1);
		}
	}

	cout << "! ";

	for(int i = 1; i <= n; ++ i) {
		cout << a[i] << " ";
	}

	cout << endl;
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

	int t;
	cin >> t;

	while(t--) {
		solve();
	}

	
	return 0;
}