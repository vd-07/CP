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
#define pb push_back

int main(){
    fastIO
    ll n,m,p;
    cin>>n>>m>>p;
    ll a[n], b[m];
    f(i,0,n) cin>>a[i];
    f(i,0,m) cin>>b[i];
    ll sum=0;
    cout<<(n+m-1)/2<<'\n';
    return 0;
}