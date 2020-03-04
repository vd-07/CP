//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define mod 1000000007
void solve(){
    ll n,p,ans=INT_MIN,index;
    cin>>n>>p;
    ll temp,a[n];
    f(i,0,n){
        cin>>a[i];
        if(p%a[i]){
            ans=p/a[i]+1;
            index=i+1;
        }
    }
    if(ans>=0){
        cout<<"YES\n";
        f(i,0,n){
            if(index-1==i)
                cout<<ans<<" ";
            else
            {
                cout<<0<<" ";
            }
            
        }
    }
    else
    {
        unordered_map<ll,ll> loc;
        f(i,0,n){
            loc[a[i]]=i;
        }
        sort(a,a+n);
        ll div=a[0],in1=0,in2;
        f(i,1,n){
            if(a[i]%div){
                ans=a[i];
                in2=loc[a[i]];
                break;
            }
            else
            {
                div=a[i];
                in1=loc[a[i]];
            }
            
        }
        if(ans>=0){
            cout<<"YES\n";
            f(i,0,n){
                if(i==in1){
                    cout<<ans/div+1<<" ";
                }
                else if(i==in2)
                    cout<<(p/ans-1)<<" ";
                    else
                    {
                        cout<<0<<" ";
                    }
                    
            }
        }
        else
        cout<<"NO\n";
    }
    
}

int main(){
    test solve();
    return 0;
}