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
    
}

int main(){
    ll n,prizes[5];
    cin>>n;
    ll points[n];
    for(int i=0;i<n;i++)
        cin>>points[i];
    for(int i=0;i<5;i++)
        cin>>prizes[i];
    sort(prizes,prizes+5);
    ll cumulative=0;
    ll ans[5]={};
    for(int i=0;i<n;i++){
        cumulative+=points[i];
        while(cumulative>=prizes[0]){
            ll index=upper_bound(prizes,prizes+5,cumulative)-prizes;
            ans[index-1]+=cumulative/prizes[index-1];
            cumulative%=prizes[index-1];
        }
    }
    for(ll e:ans)
     cout<<e<<" ";
     cout<<endl;
     cout<<cumulative;
    return 0;
}