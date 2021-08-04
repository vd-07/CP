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
    int n;
    cin>>n;
    int a[n-1];
    ll ans1=1, ans2=0;
    f(i,0,n-1){
        cin>>a[i];
        ans1^=(i+2);
        if(!(i&1)){
            ans2^=a[i];
        }
    }
    ll last=ans1^ans2;
    stack<ll> s;
    s.push(last);
    for(int i=n-2;i>=0;i--){
        last^=a[i];
        s.push(last);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}  

int main(){
    fastIO
    test solve();
    return 0;
}