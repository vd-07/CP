#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	pair<int, int> exams[n];
	int a, b;
	for(int i = 0; i < n; i++) cin >> exams[i].first >> exams[i].second;
	sort(exams, exams + n);
	for(int i = 1; i < n; i++) {
		if(exams[i].second < exams[i - 1].second)
			exams[i].second = exams[i].first;
	}
	cout << min(exams[n - 1].first, exams[n - 1].second);
	return 0;
}

