#include <bits/stdc++.h>
#define int long long int
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int **v;
int n;
int **dp;

int selectMe(int choconum, int lastselection) {
    cout << choconum << "\n";
    if(choconum > n)
        return 0;
    if(dp[choconum][lastselection] != -1)
        return dp[choconum][lastselection];
    int v1 = 0, v2 = 0, v3 = 0;
    if(lastselection != 0) {
        v1 = selectMe(choconum + 1, 0);
    }
    if(lastselection != 1) {
        v2 = selectMe(choconum + 1, 1);
    }
    if(lastselection != 2) {
        v3 = selectMe(choconum + 1, 2);
    }
    return dp[choconum][lastselection] = v[choconum][lastselection] + max({v1, v2, v3});
//    cout << v1 << " " << v2 << " " << v3 <<endl;
//    return max(v1, max(v2, v3));
}

int32_t main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    fastIO
      #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
  #endif
    dp = new int*[100001];
    for(int i = 0; i <= 100000; i++) {
      dp[i] = new int[3];
      dp[i][0] = -1; 
      dp[i][1] = -1; 
      dp[i][2] = -1;
    }
    cin >> n;
    int a1, b1, c1;
    v = new int*[100001];
    for(int i = 1; i <= n; i++) {
      v[i] = new int[3];
        cin >> a1 >> b1 >> c1;
        v[i][0] = a1;
        v[i][1] = b1;
        v[i][2] = c1;
    }
    int ans = max({selectMe(1, 0), selectMe(1, 1), selectMe(1, 2)});
    //cout << max(dp[1][0], max(dp[1][1], dp[1][2])) << endl;
    cout << ans;
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
  #endif
    delete []dp;
    delete []v;
    return 0;
}