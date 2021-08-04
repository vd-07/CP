#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> coins, int target) {

	int ans = -1;
	int currGold = 0;
	int j = 0;

	for(int i = 0; i < n; ++ i) {
		currGold += coins[i];

		while(currGold - coins[j] >= target && j < i) {
			currGold -= coins[j ++];
		}

		if(currGold >= target) {
			if(ans == -1) {
				ans = i - j + 1;
			}
			ans = min(ans, i - j + 1);
		}
	}

	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> coins(n);

	for(int i = 0; i < n; ++ i) {
		cin >> coins[i];
	}

	int target;
	cin >> target;

	int out = solve(n, coins, target);
	cout << out;

}