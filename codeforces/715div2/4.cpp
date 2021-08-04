//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n;

string process(string a, string b) {
	string ans = "";

	int p11 = -1, p21 = -1;
	int c11 = 0, c21 = 0;
	// cerr << a << endl << b << endl;
	while(c11 < 2 * n && c21 < 2 * n) {
		while(a[c11] == '0' && c11 < 2 * n) {
			++ c11;
		}
		while(b[c21] == '0' && c21 < 2 * n) {
			++ c21;
		}

		int currZero = max(c11 - p11 - 1, c21 - p21 - 1);

		while(currZero --) {
			ans += '0';
		}

		p11 = c11, p21 = c21;

		ans += '1';
		++ c11;
		++ c21;
	}
	// cerr << c11 << endl << c21;
	while(c11 < 2 * n) {
		ans += a[c11++];
	}
	while(c21 < 2 * n) {
		ans += b[c21++];
	}

	assert(ans.size() <= 3 * n);
	return ans;
}

void change(string &a) {
	for(char &i : a) {
		i = (i == '0' ? '1' : '0');
	}
}

void solve() {
	cin >> n;
	string s[3];
	vector<vector<int>> cnt(3, vector<int> (2));

	for(int i = 0; i < 3; i++) {
		cin >> s[i];
		for(int j = 0; j < 2 * n; j++) {
			cnt[i][0] += (s[i][j] == '0');
		}
		cnt[i][1] = 2 * n - cnt[i][0];
	}

	for(int i = 0; i < 3; i++) {
		for(int j = i + 1; j < 3; j++) {
			if(cnt[i][1] >= n && cnt[j][1] >= n) {
				string ans = process(s[i], s[j]);
				cout << ans << "\n";
				return;
			}
			if(cnt[i][0] >= n && cnt[j][0] >= n) {
				change(s[i]);
				change(s[j]);
				string ans = process(s[i], s[j]);
				change(ans);
				cout << ans << "\n";
				return;
			}
		}
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