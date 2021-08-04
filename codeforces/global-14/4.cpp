//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, l, r;

int choice1(vector<int> colors) {
	int ans = 0;

	int lc = 0, rc = 0;
	for(int i = 1; i <= n; i++) {
		// cerr << colors[i] << endl;
		if(colors[i] < 0) {
			colors[i] *= -1;

			ans += colors[i] / 2;

			rc += colors[i] % 2;
		} else {
			ans += colors[i] / 2;

			lc += colors[i] % 2;
		}
	}

	// cerr << lc << endl << rc << endl << ans;

	if(lc < rc) {
		swap(lc, rc);
	}

	ans += (rc) + (lc - rc);

	return ans;
}

int choice2(vector<int> colors) {
	int ans = 0;

	vector<int> l, r;

	int lc = 0, rc = 0;
	for(int i = 1; i <= n; i++) {
		if(colors[i] < 0) {
			rc += -colors[i];
			r.push_back(-colors[i]);
		} else {
			lc += colors[i];
			l.push_back(colors[i]);
		}
	}

	if(lc < rc) {
		swap(l, r);
		swap(lc, rc);
	}

	sort(l.begin(), l.end());

	int i = 0, j = 0;

	while(i < r.size()) {
		if(r[i] < l[j]) {
			l[j] -= r[i];

			++i;
		} else {
			r[i] -= l[j];
			l[j] = 0;

			++ j;
		}

		if(r[i] == 0) {
			++ i;
		}
	}

	int left = 0;

	ans = rc;

	for(int i : l) {
		ans += i / 2;
		left += i % 2;
	}

	return ans + left;
}

int choice3(vector<int> colors) {
	int ans = 0;

	vector<int> l, r;

	int lc = 0, rc = 0;
	for(int i = 1; i <= n; i++) {
		if(colors[i] < 0) {
			rc += -colors[i];
			r.push_back(-colors[i]);
		} else {
			lc += colors[i];
			l.push_back(colors[i]);
		}
	}

	if(lc < rc) {
		swap(l, r);
		swap(lc, rc);
	}

	sort(l.begin(), l.end());

	int i = 0, j = 0;

	while(i < r.size()) {
		if(r[i] < l[j]) {
			l[j] -= r[i];

			++ i;
		} else if(r[i] == l[j]) {
			l[j] = 0;
			++ i;
			++ j;

		} else {
			r[i] -= l[j];
			l[j] = 0;

			++ j;
		}
	}

	ans = rc;

	for(int i : l) {
		ans += i / 2;
		ans += i % 2;
	}

	return ans;
}

int choice4(vector<int> colors) {
	priority_queue<int> q1, q2;

	for(int i = 1; i <= n; i++) {
		if(colors[i] < 0) {
			q1.push(-colors[i]);
		} else {
			q2.push(colors[i]);
		}
	}

	int ans = 0;

	while((!q1.empty()) && (!q2.empty())) {
		int c1 = q1.top();
		int c2 = q2.top();

		// cerr << c1 << endl << c2 << endl;

		q1.pop();
		q2.pop();

		if(c1 > c2) {
			ans += c2;

			q1.push(c1 - c2);
		} else {
			ans += c1;

			q2.push(c2 - c1);
		}
	}

	while(!q1.empty()) {
		int c1 = q1.top();

		ans += c1 / 2;

		ans += c1 % 2;

		q1.pop();
	}

	while(!q2.empty()) {
		int c1 = q2.top();

		ans += c1 / 2;

		ans += c1 % 2;

		q2.pop();
	}

	return ans;
}

void solve() {
	cin >> n >> l >> r;

	vector<int> colors(n + 1);

	for(int i = 1; i <= l; i++) {
		int c;
		cin >> c;

		++ colors[c];
	}

	for(int i = 1; i <= r; i++) {
		int c;
		cin >> c;

		-- colors[c];
	}

	// int ans = choice1(colors);
	// ans = min(ans, choice2(colors));
	int ans = choice3(colors);
	// ans = min(ans, choice4(colors));

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