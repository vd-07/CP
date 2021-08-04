#include <iostream>
#include <vector>

using namespace std;

string s1, s2;
int n, m;

int min(int a, int b, int c) {
    return (a < b ? (a < c ? a : c) : (b < c ? b : c));
}

int recur(int i, int j, vector<vector<int>> &dp) {
    // i am making s1 equal to s2
    if(i == n) {
        // need to add the rest
        return m - j;
    }

    if(j == m) {
        // need to remove the rest
        return n - i;
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(s1[i] == s2[j]) {
        return dp[i][j] = recur(i + 1, j + 1, dp);
    }
    // add 
    int v1 = recur(i, j + 1, dp) + 1;
    // remove
    int v2 = recur(i + 1, j, dp) + 1;
    // replace
    int v3 = recur(i + 1, j + 1, dp) + 1;

    return dp[i][j] = min(v1, v2, v3);
}

int main() {
    cin >> s1 >> s2;

    n = s1.size();
    m = s2.size();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    cout << recur(0, 0, dp);
}