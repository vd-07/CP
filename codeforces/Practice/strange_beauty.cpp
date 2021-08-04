#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

void solve() {
    cin >> n;

    vector<int> a(n), dp(n), occurance(2e5 + 1), index(2e5 + 1, -1);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        occurance[a[i]] ++;
    }

    sort(a.begin(), a.end());


    vector<int> temp = a;
    a.clear();

    a.push_back(temp[0]);

    for(int i = 1; i < temp.size(); i++) {
        if(temp[i] != temp[i - 1]) {
            a.push_back(temp[i]);
        }
    }

    for(int i = 0; i < a.size(); i++) {
        if(index[a[i]] == -1) {
            index[a[i]] = i;
        }        
    }

    int ans = 1;

    for(int i = (int)a.size() - 1; i >= 0; i--) {
        // iterate over all the multiples of no and and find its occurance

        int currAns = 0;

        for(int multiple = 2 * a[i]; multiple <= a[n - 1]; multiple += a[i]) {

            int idx = index[multiple];

            if(idx == -1) {
                continue;
            }         

            currAns = max(currAns, dp[idx]);
        }

        dp[i] += currAns + occurance[a[i]];

        ans = max(dp[i], ans);

        // cout << dp[i] << " ";
    }

    cout << n - ans << "\n";
}

int main() {
    int t;

    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}