//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long int

vector<vector<int> > p(1000001);
vector<int> ans;
int  b[1000001];
int sum = 0, root, n;

int dfs(int u) {
  int s = b[u];
  for(auto e:p[u])  s += dfs(e);
  if(s == sum)  {
      ans.push_back(u);
      return 0;
  }
  return s;
}

void solve() {
    
    cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++) {
      cin>>a[i]>>b[i];
      sum += b[i];
      p[a[i]].push_back(i);
      if(a[i] == 0)
        root = i;
    }

    if(sum % 3) {
      cout<<-1;
      return;
    }
    sum /= 3;
    dfs(root);
    for(auto e:ans) {
      cout<<e<<" ";
    }
    cout<<endl;
    if(ans.size() >= 3) 
    cout<<ans[0]<<" "<<ans[1];
    else 
    cout<<-1;
    
}

int32_t main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  solve();
    return 0;
}