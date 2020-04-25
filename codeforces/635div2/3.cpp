//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
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
const int N = 300005;
int n, k;
vector<int> edges[N];
vector<pii> gree;
bool visited[N];

int dfs(int u, int depth = 1) {
  visited[u] = true;
  int degree = 1;
  for(auto e:edges[u]) {
    if(!visited[e]) {
      degree += dfs(e, depth + 1);
    }
  }
  gree.pb({degree, depth});
  // d2(u, d);
  return degree;
}

long long int seiz = 0;

bool comp(pii p1, pii p2) {
    if(p1.first - p1.second > p2.first - p2.second)
        return true;
    return false;
  
}
void solve(){
  cin >> n >> k;
    for(int i = 1; i <= n; i++) visited[i] = false;
  int u, v;
  for(int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    edges[v].pb(u);
    edges[u].pb(v);
  }
  dfs(1);
  // for(int i = 1; i <= n; i++) 
  //   d1(depth[i]);
  nth_element(gree.begin(), gree.begin() + n - k, gree.end(), comp);
  for(int i = 0; i < n - k; i++) {
    // d3(gree[i].second, gree[i].first.first, gree[i].first.second);
    seiz += gree[i].first - gree[i].second;
  }
  
  cout << seiz << "\n";
}

int32_t main() {
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