//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define uint unsigned long long int
#define READ(a) int a; cin>>a
#define sz(a) (int)((a).size())
#define READ2(a,b) int a,b; cin>>a>>b
#define READ3(a,b,c) int a,b,c; cin>>a>>b>>c
#define READ4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d
#define d1(a) cerr << #a << " " << a << endl;
#define d2(a, b) cerr << #a << " " << a << " " << #b << " " << b << endl;
#define d3(a, b, c) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << endl;
#define d4(a, b, c, d) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << " " << #d << " " << d << endl;
#define f(i, s, e) for(int i=s;i<e;i++)
#define READC(c) char c; cin>>c
#define READA(a,n) int a[n]; f(i,0,n) cin>>a[i]
#define READS(s) string s; cin>>s
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define int128 __int128


vector<int> edges[100010];
int color[100010] = {};
int parent[100010] = {};
int cycleCount = 0;
vector<vector<int>> vis(100010);

void dfs(int u, int p) {
  if(color[u] == 2) return;
  if(color[u] == 1) {
    cycleCount++;
    int curr = p;
    vis[cycleCount].pb(curr);
    while(curr != u) {
      curr = parent[curr];
      vis[cycleCount].pb(curr);
    }
    return;
  }
  parent[u] = p;
  color[u] = 1;
  for(auto v:edges[u]) {
    if(v == parent[u])
      continue;
    dfs(v, u);
  }
  color[u] = 2;
}

void solve(){
	READ3(n, m, k);
  int u, v;
  for(int i = 1; i <= m; i++) {
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }	

  int stored[n + 1] = {};
  if(k == 2) {
    for(int i = 1; i <= n; i++) {
      for(auto e:edges[i]) {
        stored[e]++;
      }
    }
  }
  else
  {

        for(int i = 1; i <= n; i++) {

        if(color[i] != 2) {
          dfs(i, i);
          // cout << i;
        }
      }
      
      
      for(int i = 0; i <= cycleCount; i++) {
        int si = vis[i].size();
        for(auto e:vis[i]) {
          stored[e] = max(stored[e], si);
        }
      }
    
  }
  

  
  READ(q);
  int x;
  while(q--) {
    cin >> x;
    // cout << stored[x] << "\n";
    if(stored[x] >= k)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}

int32_t main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif
  fastIO

	solve();



	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    return 0;
}