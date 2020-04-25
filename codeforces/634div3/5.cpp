//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define uint unsigned long long int
#define READ(a) int a; cin >> a
#define sz(a) (int)((a).size())
#define READ2(a, b) int a, b; cin >> a >> b
#define READ3(a, b, c) int a, b, c; cin >> a >> b >> c
#define READ4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d
#define d1(a) cerr << #a << " " << a << endl;
#define d2(a, b) cerr << #a << " " << a << " " << #b << " " << b << endl;
#define d3(a, b, c) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << endl;
#define d4(a, b, c, d) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << " " << #d << " " << d << endl;
#define f(i, s, e) for(int i = s; i < e; i++)
#define READC(c) char c; cin >> c
#define READA(a, n) int a[n]; f(i, 0, n) cin >> a[i]
#define READS(s) string s; cin >> s
#define test int t; cin >> t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back

void solve(){
  READ(n);
  READA(a, n);
  int pref[n][201];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= 200; j++) {
      pref[i][j] = 0;
    }
  }
  int x, y;
  int ans = 0;
  vector<int> adj[201];
  pref[0][a[0]] = 1;
  adj[a[0]].pb(0);
  for(int i = 1; i < n; i++) {
    for(int j = 1; j <= 200; j++) {
        pref[i][j] = pref[i - 1][j];
    }
    pref[i][a[i]] = pref[i - 1][a[i]] + 1;
    adj[a[i]].pb(i);
  }
  for(int i = 1; i <= 200; i++) {
    ans = max(ans, sz(adj[i]));
    for(int p = 0; p < sz(adj[i]) / 2; p++) {
      int l = adj[i][p] + 1, r = adj[i][sz(adj[i]) - p - 1] - 1;
      for(int e = 1; e <= 200; e++) {
        int sum = pref[r][e] - pref[l - 1][e];
        ans = max(ans, (p + 1) * 2 + sum);
      }
    }
  }
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


  test solve();



  #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
  #endif
    return 0;
}