#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int m, n;
vector<int> G[7001];
vector<int> visited;
vector<int> groups;
set<int> ans;
vector<int> p;


void detectCycles(int u, int parent) {
  
  if(visited[u] == 1) {
    int curr = parent;
   while(curr != u) {
    groups[curr] = groups[u];
    curr = p[curr]; 
   }
    return;
  }
  
  p[u] = parent;

  visited[u] = 1;
  for(auto e:G[u]) {
    if(e == parent) continue;
    detectCycles(e, u);
  }
  visited[u] = 2;
  
}

void dfs(int node) {
  visited[node] = 1;
  for(auto e:G[node]) {
   if(visited[e]) continue;
    if(groups[e] != groups[node]) {
      ans.insert(e);
      visited[node] = 2;
    }
    dfs(e);
  }
  if(visited[node] == 2)
    ans.insert(node);
}

int main() {
  cin >> m >> n;
  int u, v;
  for(int i = 1; i <= m; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  
  visited = vector<int> (n + 1, 0);
  
  groups = vector<int> (n + 1);
  
  p = vector<int> (n + 1);
  
  for(int i = 0; i < n; i++) 
    groups[i] = i;
  
  for(int i = 0; i < n; i++) {
   if(visited[i]) continue;
    detectCycles(i, i);
  }
  
  visited = vector<int> (n + 1, 0);
  
  for(int i = 0; i < n; i++) {
   if(visited[i]) continue;
    dfs(i);
  }
  
  if(ans.empty())
    cout << -1;
  else {
    int count = ans.size();
    for(auto e:ans) {
      --count;
      cout << e;
      if(count && count + 1 != (int)ans.size())
        cout << " \n";
      else if(count)
        cout << "\n";
    }

  }

  
  return 0;
}