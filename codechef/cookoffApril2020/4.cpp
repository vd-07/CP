//Author : Vivek Dubey
#include <bits/stdc++.h>
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

#define READC(c) char c; cin>>c
#define READA(a,n) int a[n]; f(i,0,n) cin>>a[i]
#define READS(s) string s; cin>>s
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define f first
#define s second
void solve(){
	READ2(h, n);
  vector<pair<pii, pii > > t0;
  int t, x, a;
  for(int i = 0; i < n; i++) {
    cin >> t >> x >> a;
    t0.pb({{x, a},{t, i}});
  }
  sort(t0.begin(), t0.end());
	vector<int> ans(n);
  int count = 0, prev;
  for(int i = 0; i < n; i++) {
    count = 0, prev = -1;
    for(int j = i + 1; j < n; j++) {
      if(t0[j].s.f == 0) {
        if(prev == -1) {
          prev = t0[j].f.s;
          if(prev >= t0[i].f.s) {
            count++;
            continue;
          }
          else
            break;
        }
        if(t0[j].f.s >= prev) count++;
        else
          break;
      }
    }
    prev = -1;
    for(int j = i + 1; j < n; j++) {
      if(t0[j].s.f == 1) {
        if(prev == -1) {
          prev = t0[j].f.s;
          if(prev <= t0[i].f.s) {
            count++;
            continue;
          }
          else
            break;
        }
        if(t0[j].f.s <= prev) count++;
        else
          break;
      }
    }
    prev = -1;
    for(int j = i - 1; j >= 0 ; j--) {
      if(t0[j].s.f == 0) {
        if(prev == -1) {
          prev = t0[j].f.s;
          if(prev >= t0[i].f.s){
            count++;
            continue;
          }
          else
            break;
        }
        if(t0[j].f.s >= prev) count++;
        else
          break;
      }
    }
    prev = -1;
    for(int j = i - 1; j >= 0; j--) {
      if(t0[j].s.f == 1) {
        if(prev == -1) {
          prev = t0[j].f.s;
          if(prev < t0[i].f.s) {
            count++;
            continue;
          }
          else
            break;
        }
        if(t0[j].f.s < prev) count++;
        else
          break;
      }
    }
    // d1(prev)
    ans[t0[i].s.s] = count;
    // cout << count << " ";
  }
  for(auto e:ans) cout << e<< " ";
  cout<<"\n";
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