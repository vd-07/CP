//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
void solve(){
    ll n;
    cin>>n;
    ll a[n],b[n],sum=0;
    f(i,0,n) cin>>a[i];
    f(i,0,n) cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    f(i,0,n) sum+=min(a[i],b[i]);
    cout<<sum<<"\n";
}

int main(){
    fastIO
    test solve();
    return 0;
}