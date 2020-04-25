//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define uint unsigned long long int
#define READ(a) int a; cin>>a
#define READ2(a,b) int a,b; cin>>a>>b
#define READ3(a,b,c) int a,b,c; cin>>a>>b>>c
#define f(i,s,e) for(int i=s;i<e;i++)
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

void solve(){
  READ(n);
  READA(a, n);
  bool mark[n + 5];
  int count;
  set<int> divisions;
  int mxN = *max_element(a, a + n);
  // int countMe[n + 5] = {};
  // for(int i = 0; i < n; i++) {
  //   countMe[a[i]]++;
  //   if(countMe[a[i]] == 3) {
  //     cout<<0<<"\n";
  //     return;
  //   }
  // }
  memset(mark, false, sizeof(mark));
  count = 0;

  for(int i = 0; i < n; i++) {
    if(mark[a[i]] == true) {
      break;
    }
    mark[a[i]] = true;
    count++;
    if(count == mxN) {
      divisions.insert(i + 1);
      break;
    }
  }

  memset(mark, false, sizeof(mark));
  count = 0;

  for(int i = n - 1; i >= 0; i--) {
    if(mark[a[i]] == true) {
      break;
    }
    mark[a[i]] = true;
    count++;
    if(count == mxN) {
      divisions.insert(i);
      break;
    }
  }
  // cout<<divisions.size()<<"\n";
  set<int> ans;
  for(auto e:divisions) {
    bool flag = true;
    vector<int> l1, l2;
    for(int i = 0; i < e; i++) {
      l1.pb(a[i]);
    }
    for(int i = e; i < n; i++) {
      l2.pb(a[i]);
    }
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    for(int i = 0; i < l1.size(); i++) {
      if(l1[i] != i + 1) {
        flag = false;
      }
    }
    for(int i = 0; i < l2.size(); i++) {
      if(l2[i] != i + 1) {
        flag = false;
      }
    }
    if(!flag)
      continue;
    ans.insert(e);
  }
  cout<<ans.size()<<"\n";
  for(auto e:ans) {
    cout<<e<<" "<<(n - e)<<"\n";
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


	test solve();



	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    return 0;
}