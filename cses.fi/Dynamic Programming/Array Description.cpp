#include <iostream>
#include <vector>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int solve() {
    int n, m;
    cin >> n >> m;

    vector<int> array(n);

    for(int &i : array) {
        cin >> i;
    }

    vector<vector<int>> dp(n, vector<int> (m + 1, 0));

    for(int i = 0; i < n; i++) {
        if(array[i] == 0) {
            // unknown
            if(i == 0) {
                dp[i] = vector<int> (m + 1, 1);
            } else {
                for(int j = 1; j <= m; j++) {
                    for(int p = -1; p < 2; p++) {
                        if(j + p >= 1 && j + p <= m)
                            dp[i][j] += dp[i - 1][j + p]; 
                        dp[i][j] %= mod;
                    }
                }
            }
        } else {
            if(i == 0) {
                dp[i][array[i]] = 1; 
            } else {
                for(int j = -1; j < 2; j++) {
                    if(array[i] + j <= m && array[i] + j >= 1)
                    dp[i][array[i]] += dp[i - 1][array[i] + j]; 
                    dp[i][array[i]] %= mod; 
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++) {
        ans += dp[n - 1][i];
        ans %= mod;
    }

    return ans;
}

int32_t main() {
    cout << solve();
    return 0;
}
