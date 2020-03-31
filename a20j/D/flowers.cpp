//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
const ll n=1000001;
ll ans[n],pref[n];
void solve(){
    ll a,b;
    cin>>a>>b;
    ll an=pref[b]-pref[a-1];
    if(an<0)
    an+=mod;
    cout<<an<<"\n";
}

int main(){
    fastIO
    ll t,k,a,b;
    cin>>t>>k;
    ans[0]=1;
    for(int i=1;i<k;i++){
        ans[i]=ans[i-1];
    }
    for(int i=k;i<=n;i++){
        //as there will be two conditions 
        // 1. When ith flower will be R, then there will be ans[i-1] 
        //    possibilites of W being in groups divisible by k
        // 2. When ith flower will be W, then there has to be k-1 more 
        //    W for the codition to be satisfied and hence fixing all k Ws
        //    we are left with arranging i-k Ws i.e. ans[i-k]
        ans[i]=(ans[i-1]+ans[i-k])%mod;
    }
    pref[0]=0;
    for(int i=1;i<=n;i++)
        pref[i]=(pref[i-1]+ans[i])%mod;
    while(t--){
        solve();
    }
    return 0;
}