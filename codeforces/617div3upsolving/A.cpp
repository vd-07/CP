//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test ll t;cin>>t;while(t--)
#define mod 1000000007
void solve(){
    int n,temp;
    int iseven=0,isodd=0;
    cin>>n;
    f(i,0,n){
        cin>>temp;
        if(temp&1)
            isodd++;
        else
        {
            iseven++;
        }
        
    }
    if(n==isodd&&n%2==0)
    cout<<"NO\n";
    else if(isodd)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}


int main(){
    fastIO
    test solve();

    return 0;
}
