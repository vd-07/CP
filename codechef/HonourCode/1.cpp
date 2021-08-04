//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define mod 1000000007

void solve(){ 
    string s;
    cin>>s;
    ll n=s[s.size()-1]-'0';
    if(s.size()>1)
    n+=10*(s[s.size()-2]-'0');
    int x=n%4;
    if(x==0)
        cout<<s;
    else if(x==1)
        cout<<1;
    else if(x==3)
        cout<<0;
    else
    {
        int carry=1,num;
        for(int i=(int)s.size()-1;i>=0;i--){
            num=(s[i]-'0')+carry;
            s[i]=(num%10)+'0';
            carry=num/10;
        }
        if(carry!=0)
        cout<<carry<<s;
        else
        cout<<s;
    }
    
}

int main(){
    solve();
    return 0;
}