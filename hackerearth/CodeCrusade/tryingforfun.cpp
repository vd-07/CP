#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int distinctPF[N + 1];
int x, n;
int a[N + 1];

void sieve() {
	for(int i = 0; i <= N; i++) distinctPF[i] = 0;
	for(int i = 2; i <= N; i++) {
		if(!distinctPF[i]) 
		for(int j = i; j <= N; j += i)
			distinctPF[j]++;
	}
}
bool comp(pair<int, int> p1, pair<int, int> p2) {
	if(p1.first < p1.second)
		return true;
	return false;
}
void solve() {
	cin >> x >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans, thans = N;
	set<pair<pair<int, int>, int> > s;
	for(int i = 1; i <= x; i++) {
		s.insert({{distinctPF[a[i]], i}, a[i]});
		// cout << ans << "\n";
	}
	thans = s.rbegin()->second;
	for(int i = x + 1; i <=n; i++) {
		s.insert({{distinctPF[a[i]], i}, a[i]});
		s.erase({{distinctPF[a[i - x]], i - x}, a[i - x]});
		ans = s.rbegin()->second;
		thans = min(thans, ans);
		// cout << thans << " ";
		// cout << ans << "\n";
	}
	cout << thans;
}

int main() {
	sieve();
	solve();
	return 0;
}