#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
int n, k;
vector<int> factors[2001];
int dp[2001][2001];

int calc(int num, int count) {
	if(k == 1)
		return 1;
	if(count == k - 1)
		return factors[num].size();
	if(dp[num][count] != -1)
		return dp[num][count];
	int ans = 0;
	for(auto X:factors[num])
		ans = (ans % mod + calc(X, count + 1) % mod) % mod;
	return dp[num][count] = ans;
}

int main() {
	for(int i = 1; i <= 2000; i++) {
		for(int j = 1; j * j <= i; j++) {
			if(i % j)
				continue;
			factors[i].push_back(j);
			if(j * j != i)
				factors[i].push_back(i / j);
		}
	}
	for(int i = 0; i <= 2000; i++) {
		for(int j = 0; j <= 2000; j++)
			dp[i][j] = -1;
	}
	cin >> n >> k;
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans =(	ans % mod + calc(i, 1) % mod) % mod;	
	cout << ans;
	return 0;
}

