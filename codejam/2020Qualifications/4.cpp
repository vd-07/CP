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
  int matrix[n][n];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }
  int trace = 0, r = 0, c = 0;
  for(int i  = 0; i < n; i++) {

    bool augR[n + 1] ,
         augC[n + 1] ,
         isFoundR = true,
         isFoundC = true;
    memset(augR, false, sizeof(augR));
    memset(augC, false, sizeof(augC));
    for(int j = 0; j < n; j++) {
      if(i == j) trace += matrix[i][j];

      if(augR[matrix[i][j]] && isFoundR) {
        r++;
        isFoundR = false;
      }
      if(augC[matrix[j][i]] && isFoundC) {
        c++;
        isFoundC = false;
      }
      augR[matrix[i][j]] = true;
      augC[matrix[j][i]] = true;
    }
  }
	cout << trace << " " << r << " " << c << "\n";
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