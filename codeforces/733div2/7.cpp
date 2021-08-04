#include "bits/stdc++.h"
using namespace std;

void solve(int saving, vector<int> currentValue, vector<int> futureValue) {
    int n = currentValue.size();
    int dp[n + 1][saving + 1];
    for (int i = 0; i < n; i++) {
        futureValue[i] -= currentValue[i];
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= saving; j++) {
            if (j >= currentValue[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - currentValue[i - 1]] + futureValue[i - 1]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }


    cout << dp[n][saving];
}

int32_t main() {
#ifdef CODINGINVEINS
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
    while (t--) {
        int savings;
        cin >> savings;

        int n;
        cin >> n;

        vector<int> currentValue(n), futureValue(n);
        for(int &i: currentValue) {
            cin >> i;
        }
        for(int &i: futureValue) {
            cin >> i;
        }

        solve(savings, currentValue, futureValue);
    }

#ifdef CODINGINVEINS
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}