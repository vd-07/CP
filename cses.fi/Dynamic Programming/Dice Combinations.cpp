//Author : Vivek Dubey
#include <iostream>
#include <cstring>
using namespace std;

#define ll long long
 
const int mod = 1e9 + 7;
const int mxN = 1e6 + 1;

int n, m;
int dp[mxN];

void solve() {
	memset(dp, 0, sizeof(dp));
	cin >> n;
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 6 && i - j >= 0; j++) {
			dp[i] += dp[i - j];
			dp[i] %= mod;
		}
	}
	cout << dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();

	}
	return 0;
}
