//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define READ(a) ll a; cin>>a
#define READ2(a,b) ll a,b; cin>>a>>b
#define READ3(a,b,c) ll a,b,c; cin>>a>>b>>c
#define f(i,s,e) for(ll i=s;i<e;i++)
#define READC(c) char c; cin>>c
#define READA(a,n) ll a[n]; f(i,0,n) cin>>a[i]
#define READS(s) string s; cin>>s
#define FILL(x,y) memset(x,y,sizeof(x))
#define test ll t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define int128 __int128
// Guide on how to use 128 bit integer on g++
// __int128 v=2;
//     printf("%llu", v);

ll XOR(const ll n) 
{ 
    switch (n & 3) { 
    case 0: return n; 
    case 1: return 1; 
    case 2: return n + 1; 
    case 3: return 0; 
    } 
} 

void solve(){
	 ll n, q;
  set<ll> s;
  map<ll, ll> nxt;
  cin >> n >> q;
  s.insert(n + 1);
  while(q--)
  {
    ll c, x;
    cin >> c >> x;
    if(c == 1)
    {
      nxt[x] = x + 1;
      s.insert(x);
    }
    else
    {
      while(nxt.count(x))
      {
        if(nxt.count(nxt[x]))
          nxt[x] = nxt[nxt[x]];
        x = nxt[x];
      }
      auto it = s.lower_bound(x);
      ll ans = XOR(*it - 1) ^ XOR(x - 1);
      cout << ans << "\n";
    }
  }
}

int main(){
  fastIO
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif


	solve();



	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    return 0;
}