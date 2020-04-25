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

int sf[1002];
void sieve(int N) {
  for(int i = 1; i <= N; i++)
    sf[i] = i;
  for(int i = 2; i <= N; i++) {
    if(sf[i] == i) {
      for(int j = i; j <= N; j += i)
        if(sf[j] == j) sf[j] = i;
    }
  }
}
void solve(){
  READ(n);
  READA(a, n);
  map<int, int> fac;
  int count = 1;
  for(int i = 0; i < n; i++) {
    int mii = sf[a[i]];
    

    if(fac.find(mii) != fac.end()) {
      a[i] = fac[mii];
      continue;
    }
    fac[mii] = count;
    a[i] = count;
    count++;
  }
  cout<<fac.size()<<"\n";
  for(auto e:a) {
    cout<<e<<" ";
  }
  cout<<"\n";
}

int32_t main(){
  sieve(1001);
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