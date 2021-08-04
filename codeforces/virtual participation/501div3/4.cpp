//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, k, s;
ll steps(ll curr, ll d) {
	// cout<<curr<<" "<<d<<endl;
	if(curr - d > 0)
		return curr - d;
	else
		return curr + d;
}

void solve(){
  cin>>n>>k>>s;
  if(k > s || k * (n - 1) < s) {
  	cout<<"NO";
  	return;
  }
  cout<<"YES\n";
  ll curr = 1;
  while(k > 0) {
  	ll d = min(n-1, s - k + 1);
  	curr = steps(curr, d);
  	cout<<curr<<" ";
  	k--;
  	s -= d;
  }

}

int main(){
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