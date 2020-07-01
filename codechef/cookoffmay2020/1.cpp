//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN  200001
int a[MAXN];
int n;
void solve() {
    cin >> n;
    bool found1 = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        found1 |= (a[i] == 1);
    }
    if(found1) 
        cout << -1;
    else
        cout << 1;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
