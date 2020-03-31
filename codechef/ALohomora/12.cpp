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
    ll pr=0,pl=0,pd=0,pu=0;
    for(int i=0;i<s.size();i++){
        ll ar=0,al=0,ad=0,au=0;
        while(s[i+ar]=='R'&&i+ar<s.size())
            ar++;
        while(s[i+al]=='L'&&i+al<s.size())
            al++;
        while(s[i+ad]=='D'&&i+ad<s.size())
            ad++;
        while(s[i+au]=='U'&&i+au<s.size())
            au++;
        i+=max(ad,max(au,max(al,ar)))-1;
        pl+=(l-al-pl!=0)*al;
        pr+=(r-ar-pr!=0)*ar;
        pd+=(d-ad-pd!=0)*ad;
        pu+=(u-au-pu!=0)*au;
    }
    cout<<"L : "<<pl<<" R : "<<pr<<" U : "<<pu<<" D : "<<pd<<"\n";
    cout<<(l*d-max(pu,pd)*max(pl,pr))<<"\n";
}

int main(){
    fastIO
    test solve();
    return 0;
}