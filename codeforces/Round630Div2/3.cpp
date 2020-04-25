#include <iostream>
using namespace std;

const int mxN = 200007;

int n, k;
int cnt[mxN][26];
string s;

int differ(int u, int v) {
  int ret = 0, mx = 0;
  for(int i = 0; i < 26; i++) {
    ret += cnt[u][i] + cnt[v][i];
    mx = max(mx, cnt[u][i] + cnt[v][i]);
  }
  return ret - mx;
}

int main() {
  int t;
  cin>>t;
  while(t--) {
    cin>>n>>k;
    cin>>s;
    for(int i = 0; i < k; i++) {
      for(int j = 0; j < 26; j++) {
        cnt[i][j] = 0;
      }
    }
    for(int i = 0; i < n; i++) {
      cnt[i%k][s[i] - 'a']++;
    }
    int ans = 0;
    for(int  i = 0; i < k; i++) {
      ans += differ(i, k - i - 1);
    }
    cout<<ans/2<<"\n";
  }
  return 0;
}