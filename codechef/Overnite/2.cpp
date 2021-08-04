//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define mod 1000000007
void solve(){ 

}

int main(){
    ll n;
    cin>>n;
    ll a[n],b[n];
    f(i,0,n)
        cin>>a[i];
    f(i,0,n)
        cin>>b[i];
    ll cost=0,d=0;
    for(ll i=n-1;i>=0;i--){
        a[i]+=d;
        if(a[i]%b[i]){
            cost+=(i+1)*(b[i]-a[i]%b[i]);
            d+=b[i]-a[i]%b[i];
        }
    }
    cout<<cost;
    return 0;
}