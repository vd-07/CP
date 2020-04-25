//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define uint unsigned long long int
#define READ(a) int a; cin>>a
#define READ2(a,b) int a,b; cin>>a>>b
#define READ3(a,b,c) int a,b,c; cin>>a>>b>>c
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

int power(int x, int y, int p) 
{ 
    int res = 1; 
    x = x % p;  
    while (y > 0){ 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
int modInverse(int n, int p) 
{ 
    return power(n, p-2, p)%p; 
}

void solve(){
  READ(n);
  READA(a, n);
  int prefMax[n];
  prefMax[0] = a[0];
  for(int i = 1; i < n; i++) {
    prefMax[i] = max(prefMax[i - 1], a[i]);

  }

  int T = -1, t, t1, ans[n];

  for(int i = n - 1; i >= 0; i--) {
    if(a[i] == prefMax[i]) continue;

    t = prefMax[i] - a[i];
    t = ceil(log2(t));

    a[i] = a[i] + (1 << t);

    if(i == n - 1) {
      T = t;
      ans[n - 1] = T;
      continue;
    }

    T = max(t, T);

    if(a[i] > a[i + 1]) {
      t1 = a[i] - a[i + 1];
      t1 = ceil(log2(t1));
      t1 = max(t1 + 1, t);
      if(t1 < T)
        T++;
      else
        T = t1;
      T = max(T + 1, t1);
    }
    
    // d3(a[i], T, ans[i]);
    ans[i] = T;
    d3(a[i], T, ans[i]);
  }

  if(T == -1)
    cout << 0 << "\n";
  else
  cout << (T + 1) << "\n";
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