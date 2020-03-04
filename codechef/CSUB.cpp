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
    int n;
    string s;
    cin>>n;
    cin>>s;
    ll ct=0;
    f(i,0,n)
        {
            if(s[i]=='1')
                ct++;
        }
    cout<<(ct*(ct+1))/2<<endl;
}


int main(){
    fastIO
    test solve();

    return 0;
}