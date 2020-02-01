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
    cin>>n;
    string s;
    cin>>s;
    int count=n,last=0,diff=0;
    for(int i=0;i<n;i++){
            diff=0;
            while(last-diff>=0&&i+diff<n&&s[last-diff]=='a'&&s[i+diff]=='b')
                {
                    count-=2;
                    diff++;
                }
        last=i-1;
        i=i+diff;
    }
    cout<<count;
}


int main(){
    fastIO
    solve();

    return 0;
}