#include <bits/stdc++.h>
using namespace std;
#define int long long int

int n, r;
int arr[45];

int devise(int index = 1, int chosen = 0, int currAnd = -1) {
    cout << index << " " << chosen << endl;
    if(chosen == r) {
      cout << currAnd << endl;
      cout << endl;
      // return chosen == 0 ? arr[index] : currAnd;
      return currAnd;
    }
    if(index == n) {
      cout << currAnd<< endl;
      cout << endl;
      
      return chosen == r - 1 ? currAnd & arr[index] : -1;
    }
    int v1 = -1, v2 = -1;
    if(r - chosen == n - index + 1) {
        v2 = devise(index + 1, chosen + 1, chosen == 0 ? arr[index] : currAnd & arr[index]);
        
    } else {
        v1 = devise(index + 1, chosen, currAnd);
        v2 = devise(index + 1, chosen + 1, chosen == 0 ? arr[index] : currAnd & arr[index]);
    }
    cout << index << " " << v1 << ' ' << v2 << endl << endl;
    if(v1 == -1 && v2 == -1)
      return arr[index];
    if(v1 == -1 || v2 == -1)
      return max(v1, v2);
    return min(v1, v2);
}
void solve() {
    cin >> n >> r;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    int ans = devise();
    cout << ans << "\n";
}

int32_t main(){
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
  #endif


  int t;
  cin >> t;
  while(t--) solve();



  #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
  #endif
    return 0;
}