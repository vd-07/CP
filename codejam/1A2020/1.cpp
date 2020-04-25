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

bool comp(pair<string, int> p1, pair<string, int> p2) {
  if(p1.second < p2.second)
    return true;
  return false;
}

void solve(){
	READ(n);
  vector<string> s(n);
  vector<pair<string, int> > temp(n);
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }

  string ans = "";
  int count = 0;

  while(count < n) {
    //getting substring
    for(int i = 0; i < n; i++) {
      // d2(s[i], i);
    temp[i].first = "", temp[i].second = 0;
    if(s[i] == "") {
        count++;
        continue;
        
    }
    auto ii = s[i].find("*");
    //handling corner cases
    if(s[i][0] == '*') {
        s[i].erase(0, 1);
        continue;
    }
    if(ii == string::npos) {
      temp[i] = {s[i], s[i].size()};
      s[i] = "";
      continue;
    }
    temp[i] = {s[i].substr(0, ii), ii};
    s[i].erase(0, ii + 1);
    }

    if(count == n)
      break;
    count = 0;

    sort(temp.begin(), temp.end(), comp); 

    for(int i = 1; i < n; i++) {
      // d2(temp[i].first, temp[i - 1].first);
      if(temp[i - 1].first == "") {
        continue;
      }
      if(temp[i].first.find(temp[i-1].first) == string::npos) {
        cout << "*" << "\n";
        return;
      }
    }
    
    // d2(count, ans);
    
    ans += temp[n-1].first;
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

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
      cout << "Case #"<<i<<": ";
      solve();
    }
	



	// #ifndef ONLINE_JUDGE
 //    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	// #endif
    return 0;
}