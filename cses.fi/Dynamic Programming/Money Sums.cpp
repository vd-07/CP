#include <iostream>
#include <vector>
using namespace std;

int findSum(vector<int> x) {
    int sum = 0;
    for(int val : x) {
        sum += val;
    }
    return sum;
}

void recur(int i, int sum, vector<int> &x, vector<vector<bool>> &dp) {
    if(dp[sum][i]) {
        return;
    }

    dp[sum][i] = true;

    if(i >= x.size()) {
        return;
    }

    recur(i + 1, sum + x[i], x, dp);
    recur(i + 1, sum, x, dp);
}

vector<int> solve(vector<int> x, int n) {
    int sum = findSum(x);
    vector<int> dp(sum + 1, -2);

    vector<int> ans;

    dp[0] = -1;

    for(int s = 1; s <= sum; s++) {
        for(int j = 0; j < n; j++) {
            if(x[j] < s && dp[s - x[j] != -2]) {
                if(dp[s - x[j]] < j) {
                    dp[s] = j;
                    ans.push_back(s);
                    break;
                }
            }
        }
    }
    
    return ans;
}

void printAns(vector<int> ans) {
    cout << ans.size() << '\n';
    for(int val : ans) {
        cout << val << " ";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n);

    for(int i = 0; i < n; i++) {
        cin >> x[i];
    } 
    
    printAns(solve(x, n));

    return 0;
}