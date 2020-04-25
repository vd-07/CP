//Author : Vivek Dubey
#include <iostream>
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


string digits[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string p[2005];
int n;
int count[2005][10];

int diffUs(string s1, string s2) {
  int ct = 0;
  for(int i = 0; i < 7; i++)
    if(s1[i] != s2[i]) ct++;
  return ct;
}
void processUs() {
  for(int i = 0; i < n; i++) {
    // string is p[i]
    for(int j = 0; j < 10; j++) {
      count[i][j] = diffUs(digits[j], p[i]);
      // d1(count[i][j]);
    }
  }
}
void solve(){
  cin >> n;
  int k;
  cin >> k;
  // int min[n], max[n];
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  } 
  processUs();
  string ans = "";
  int suff[n + 1];
  suff[n - 1] = 7;
  for(int i = 0; i < 10; i++)
    suff[n - 1] = min(suff[n - 1], count[n - 1][i]);
  // d1(suff[n - 1])
  for(int i = n - 2; i >= 0; i--) {
    suff[i] = 7;
    for(int j = 0; j < 10; j++)
    suff[i] = min(suff[i], count[i][j]);
    suff[i] += suff[i + 1];
  }

  //min changes greater than changes to make
  if(suff[0] > k) {
    cout << -1;
    return;
  }
  // zero changes at n (0 indexing)
  suff[n] = 0;

  for(int i = 0; i < n; i++) {
    int sel = -1;
    for(int j = 9; j >= 0; j--) {
      if(k - count[i][j] >= suff[i + 1]) {
        sel = j;
        k -= count[i][j];
        // d1(j);
        break;
      }
    }
    if(sel == -1) {
      cout << -1;
      return;
    }
      // d1(sel)
    ans += (sel + '0');x
  }
  int i = n - 1;
  while(k != 0 && i != -1) {
    // vector<pii> dd;
    int maxX = 0, sel = -1;
    k += diffUs(digits[ans[i] - '0'], p[i]);
    for(int j = 0; j < 10; j++) {
      if(k - count[i][j] >= 0 && maxX < count[i][j]) {
        sel = j;
        maxX = count[i][j];
      }
    }
    if(sel == -1) {
      cout << -1;
      return;
    }
    if(ans[i] != (sel + '0')) {
      ans[i] = sel + '0';
      k -= maxX;
    }
    i--;
  }
  if(k != 0) cout << -1;
  else
  cout << ans;
}

int32_t main(){
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