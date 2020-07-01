#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        unordered_set<string> dict;
        string s;
        cin >> s;
        int k;
        cin >> k;
        string temp;
        while(k--) {
            cin >> temp;
            dict.insert(temp);
        }
        bool dp[s.size()] = {};
        if(dict.count(s.substr(0, 1)))
            dp[0] = true;
        if(s.size() > 1 && dict.count(s.substr(0, 2)))
            dp[1] = true;
        if(s.size() > 2 && dict.count(s.substr(0, 3)))
            dp[2] = true;
        for(int i = 1; i < s.size(); i++) {
            dp[i] |= dp[i - 1] & dict.count(s.substr(i, 1));
            if(i + 1 < s.size())
                dp[i + 1] |= dp[i - 1] & dict.count(s.substr(i, 2));
            if(i + 2 < s.size())
                dp[i + 2] |= dp[i - 1] & dict.count(s.substr(i, 3));
        }
        cout << (dp[s.size() - 1] ? "YES\n" : "NO\n");
    }
    return 0;
}
