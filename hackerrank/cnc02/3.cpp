#include <bits/stdc++.h>
#define int unsigned long long int
using namespace std;

int v[100001][3];
int n;
int dp[100001][3];

int selectMe(int choconum, int ans, int lastselection) {
    if(dp[choconum][lastselection] != -1)
        return dp[choconum][lastselection];
    if(choconum == n)
        return ans;
    int v1 = selectMe(choconum +1, ans + v[choconum][0], 0), 
                    v2 = selectMe(choconum + 1, ans + v[choconum][1], 1),
                    v3 = selectMe(choconum + 1, ans + v[choconum][2], 2);
    if(lastselection == 0)
        if(v2 > v3)
            return dp[choconum][1] = v2;
        else
            return dp[choconum][2] = v3;
    else if(lastselection == 1) 
        if(v1 > v3)
            return dp[choconum][0] = v1;
        else
            return dp[choconum][2] = v3;
    else
        if(v1 > v2)
            return dp[choconum][0] = v1;
        else
            return dp[choconum][2] = v2;
//    cout << v1 << " " << v2 << " " << v3 <<endl;
    return max(v1, max(v2, v3));
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    for(int i = 0; i <= 100000; i++) dp[i][0] = -1, dp[i][1] = -1, dp[i][2] = -1;
    cin >> n;
    int a1, b1, c1;
    for(int i = 0; i < n; i++) {
        cin >> a1 >> b1 >> c1;
        v[i][0] = a1;
        v[i][1] = b1;
        v[i][2] = c1;
    }
    int ans = selectMe(0, 0, -1); 
    cout << ans;
    return 0;
}
