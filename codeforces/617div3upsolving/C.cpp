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
    int l=-1,r=n,x=0,y=0;
    map<pair<int,int>,int> mp;
    mp[{0,0}]=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='L')
            x--;
        if(s[i]=='R')
            x++;
        if(s[i]=='U')
            y++;
        if(s[i]=='D')
            y--;
        if(mp.find({x,y})!=mp.end())
        {
            if(i-mp[{x,y}]<r-l)
            {
                l=mp[{x,y}]+1;
                r=i;
            }
        }
        mp[{x,y}]=i;
    }
    // for(auto itr=mp.begin();itr!=mp.end();itr++)
    //     cout<<((itr->first).first)<<" "<<((itr->first).second)<<" "<<((itr->second))<<endl;
    if(l==-1&&r==n)
        cout<<-1<<"\n";
    else
    cout<<l+1<<" "<<r+1<<"\n";
}


int main(){
    fastIO
    test solve();

    return 0;
}
