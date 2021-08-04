//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define READ(a) ll a; cin>>a
#define READ2(a,b) ll a,b; cin>>a>>b
#define f(i,s,e) for(int i=s;i<e;i++)
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

void solve(){
    ll sum = 0;
    // vector<ll> mins;
    READ2(n,k);
    READA(a,n);
    // ll mxN = *max_element(mins.begin(), mins.end());
    ll start = 1, end = a[n-1] - a[0];
    while(start < end) {
    	ll mid = (start + end) / 2;
    	sum = 0;
    	for(ll  i = 1; i < n; i++) {
    		ll d = a[i] - a[i-1];
    		sum += (d + mid - 1) / mid - 1;
    		// if(k < sum) {
     	// 	start = mid + 1;
     	// 	break;
     	// 	}
    	}
		if(k >= sum)
		end = mid;     	
		else
		start = mid + 1;
     	//cout<<start<<" "<<end<<" "<<i<<endl;
     	// if(start == end) {
     	// 	// i = end; 
     	// 	break;
     	//  }
 	}
	cout<<start<<"\n";
}

int main(){
	
	// #ifndef ONLINE_JUDGE
 //    // for getting input from input.txt
 //    freopen("input.txt", "r", stdin);
 //    // for writing output to output.txt
 //    //this can be opted out if you want to print the output to the sublime console
 //    freopen("output.txt", "w", stdout);
	// #endif

	ll t;
	cin>>t;
	for(int i=1;i<=t;i++) {
	    cout<<"Case #"<<i<<": ";
	    solve();
	}
    return 0;
}