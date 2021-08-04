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

void solve(){
    string s;
    cin>>s;
    ll r=0,u=0, l=0, d=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='R')
            r++;
        if(s[i]=='L')
            l++;
        if(s[i]=='D')
            d++;
        if(s[i]=='U')
            u++;
        // if((u!=0||d!=0)&&(r!=0||l!=0)){
        //     l=0,r=0,d=0,u=0;
        // }
    }
    // ll bl=l,br=r,bu=u,bd=d,ans=0, al=0, ar=0, ad=0, au=0;
    // for(int i=0;i+1<s.size();i++){
    //     if(s[i]=='L'){
    //         if(l>1&&s[i+1]!='L')
    //             al++;
    //         l--;
    //     }
    //     if(s[i]=='U'){
    //         if(u>1&&s[i+1]!='U')
    //             au++;
    //         u--;
    //     }
    //     if(s[i]=='D'){
    //         if(d>1&&s[i+1]!='D')
    //             ad++;
    //         d--;
    //     }
    //     if(s[i]=='R'){
    //         if(r>1&&s[i+1]!='R'){
    //             ar++;
    //             ctr=0;
    //         }
    //         if(s[i+1]=='R')
    //             ctr++;
    //         r--;
    //     }
    // }


    cout<<<<"\n";
}

int main(){
    fastIO
    test solve();
    return 0;
}