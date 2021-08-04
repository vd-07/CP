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
    ll s, res=0;
    cin>>s;
    while(s>9){
        res+=s-s%10;
        s=s/10+s%10;
    }
    cout<<res+s<<"\n";
}


int main(){
    fastIO
    test solve();

    return 0;
}
