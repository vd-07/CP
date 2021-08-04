// just a problem

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> seats(n);
	vector<pair<int, int>> occupied;

	for(int i = 0; i < n; ++ i) {
		char c;
		cin >> c;

		if(c == '_') {
			seats[i] = 0;
		} else {
			seats[i] = c - '0';
			occupied.push_back({seats[i], i});
		}
	}

	int curr;
	cin >> curr;

	int before = n;
	for(int i = 0; i < occupied.size(); ++ i) {
		if(occupied[i].first < curr) {
			before = occupied[i].second;
		} else {
			break;
		}
	}

	int after = n;
	for(int i = (int)occupied.size() - 1; i >= 0; -- i) {
		if(curr < occupied[i].first) {
			after = occupied[i].second;
		} else {
			break;
		}
	}
	cerr << before << endl << after << endl;
	if(before + 1 != after) {
		cout << "0\n";
		return;
	}

	int countBefore = 0;

	for(int i = before; i >= 0; -- i) {
		if(seats[i] == 0) {
			break;
		}
		++ countBefore;
	}

	int countAfter = 0;

	for(int i = after; i < n; ++ i) {
		if(seats[i] == 0) {
			break;
		}
		++ countAfter;
	}

	if(after == n) {
		cout << countBefore << "\n";
		return;
	}

	if(before == 0) {
		cout << countAfter << "\n";
		return;
	}

	cout << min(countAfter, countBefore) << "\n";
}

int main() {

	int t;
	cin >> t;

	while(t--) {
		solve();
	}

	
	return 0;
}