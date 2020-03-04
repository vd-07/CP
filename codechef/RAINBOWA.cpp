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
    int a[n];
    f(i,0,n)
        cin>>a[i];
    if(a[0]!=1||*min_element(a,a+n))
    {   
        cout<<"no\n";
        return;
    }
    int count=0;
    for(int i=0,j=n-1;i<j;i++,j--){
        if(a[i]==a[j]){
            if(a[i]==a[i+1]||a[i]==a[i+1]-1)
            count++;
        }
    }
    if(count==(n)/2)
        cout<<"yes\n";
    else
    {
        cout<<"no\n";
    } 
}


int main(){
    fastIO
    test solve();

    return 0;
}