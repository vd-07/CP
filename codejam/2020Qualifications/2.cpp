//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define uint unsigned long long int
#define READ(a) int a; cin>>a
#define READ2(a,b) int a,b; cin>>a>>b
#define READ3(a,b,c) int a,b,c; cin>>a>>b>>c
#define READC(c) char c; cin>>c
#define READA(a,n) int a[n]; f(i,0,n) cin>>a[i]
#define READS(s) string s; cin>>s
#define FIint(x,y) memset(x,y,sizeof(x))
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define int128 __int128
#define f first
#define ff first.first
#define fs first.second
#define s second
#define sf second.first
#define ss second.second

vector<pair< pii, int> > tasks;
void solve() {
  tasks.clear();
  READ(n);
  int start, end;
  for(int i = 0; i < n; i++) {
    cin >> start >> end;
    tasks.pb({{start, end}, i});
  }
  string ans(n, '#');
  sort(tasks.begin(), tasks.end());

  ans[tasks[0].s] = 'J', ans[tasks[1].s] = 'C';
  int ppEnd = tasks[0].fs, pEnd = tasks[1].fs;
  char ppChar = 'J', pChar = 'C';
  for(int i = 2; i < tasks.size(); i++) {
      if(tasks[i].ff >= ppEnd) {
          ans[tasks[i].s] = ppChar;
          ppEnd = tasks[i].fs;
      }
      else if(tasks[i].ff >= pEnd) {
          ans[tasks[i].s] = pChar;
          pEnd = tasks[i].fs;
      }
      else {
          cout << "IMPOSSIBLE\n";
          return;
      }
      // cout << ans << "\n";
  }
  // cout << endl;
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
  for(int i = 1; i <=t; i++) {
    cout << "Case #"<<i<<": ";
    solve();
  }



	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    return 0;
}