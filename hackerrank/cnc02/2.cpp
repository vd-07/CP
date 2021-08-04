#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int mxN = 100001;
vector<int> edges[mxN];
int n, m;
bool visited[mxN], isGuarded[mxN];
int ans = 0;
void dfs(int u) {
    visited[u] = true;
    if(isGuarded[u])
        return;
    ans++;
    for(auto e:edges[u]) {
        if(!visited[e]) dfs(e);
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    for(int i = 0; i < mxN; i++) {
        visited[i] = false;
    }
    cin >> n;
    cin >> m;
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u;
        isGuarded[u] = true;
    }
    for(int i = 0; i < n -1 ; i++) {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1);
    cout << ans;
    return 0;
}
