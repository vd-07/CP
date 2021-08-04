//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define pii pair<int, int>
ll solve2(ll *X, ll *Y, ll n){
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        ans+=X[i]*Y[i+1];
    }
    for(ll i=n-1;i>0;i--)
        ans-=X[i]*Y[i-1];
    return ans/2;
}
void solve(){
    string s;
    cin>>s;
    ll x=0,y=0;
    ll n=s.size();
    ll X[n], Y[n];
    for(ll i=0;i<n;i++){
        if(s[i]=='L')
            x--;
        if(s[i]=='R')
            x++;
        if(s[i]=='U')
            y++;
        if(s[i]=='D')
            y--;
        X[i]=x,Y[i]=y;
    }
    cout<<abs(solve2(X,Y,n))<<"\n";   
}

int main(){
    fastIO
    test solve();
    return 0;
}