#include <iostream>
using namespace std;

int a, b;
int dp[501][501];

int solve(int a, int b) {
    if(a == b) {
        return 0;
    }
    if(dp[a][b] != -1) {
        return dp[a][b];
    }

    int ans = 1e9;
    for(int i = 1; i < a; i++) {
        ans = min(ans, solve(a - i, b) + solve(i, b) + 1);
    }
    for(int i = 1; i < b; i++) {
        ans = min(ans, solve(a, b - i) + solve(a, i) + 1);
    }
    return dp[a][b] = ans;
}

int main() {
    cin >> a >> b;

    for(int i = 0; i <= a; i++) {
        for(int j = 0; j <= b; j++) {
            dp[i][j] = -1;
        }
    }
    
    cout << solve(a, b);
    return 0;    
}