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
    int len=0,ct;
    for(int i=0;i<s.size();i++){
        for(int j=(int)s.size()-1;j>=0;j--)
        {
            if(s[i]==s[j]){
                ct=1;
                int k,l=i+1;
                for(k=j-1;k>=0;k--){
                    if(s[k]==s[l])
                    ct++,l++;
                    else
                    break;
                }
                j=k;
                len=max(len,ct);
            }
        }
    }
    cout<<len;
}


int main(){
    fastIO
    solve();

    return 0;
}
