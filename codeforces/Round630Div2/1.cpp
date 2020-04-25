//Author : Vivek Dubey
#include <iostream>
using namespace std;
#define int long long int

int a, b, c, d;
int x, y, x1, y12, x2, y2;
bool checker(int c1, int c2) {
  if(c1 < x1 || c1 > x2 || c2 > y2 || c2 < y12) 
    return false;
  return true;
}
void solve(){
  
  cin >> a >> b >> c >> d;
  cin >> x >> y >> x1 >> y12 >> x2 >> y2;
  int mx = abs(a - b), my = abs(c - d);
  int c1 = 0, c2 = 0;
  if((mx == 0) && (a != 0)) {
    if(checker(x + 1, y) || checker(x - 1, y))
      c1 = 1;
    else c1 = 2;
  }
  if((my == 0) && (c != 0)) {
    if(checker(x, y + 1) || checker(x, y - 1))
      c2 = 1;
    else
      c2 = 2;
  }
  if(a > b) mx = -mx;
  if(c > d) my = -my;
  if(c1 == 0) {
    if(checker(x + mx, y))
      c1 = 1;
  }
  if(c2 == 0) {
    if(checker(x, y + my))
      c2 = 1;
  }
  // cout<<mx<<" "<<my<<endl;
  if(c1 == 1 && c2 == 1)
    cout<<"YES\n";
  else
    cout<<"NO\n";
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
  while(t--) solve();



  // #ifndef ONLINE_JUDGE
  //   cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
  // #endif
    return 0;
}