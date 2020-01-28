//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define mod 1000000007

// void solve(){
    
// }

int main(){
    // test solve();
    int q,x,num;
    cin>>q>>x;
    int a[1000000]={},hi=0;
    while(q--){
        cin>>num;
        a[num%x]++;
        while(a[(hi)%x]>=(hi-hi%x)/(x)+1)
        hi++;
        cout<<hi<<"\n";
    }
    return 0;
}