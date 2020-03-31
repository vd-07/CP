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
#define pb push_back

void solve(){
    int n,m;
    cin>>n>>m;
    int maxi=0, temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        maxi+=temp;
    }
    cout<<min(maxi,m)<<"\n";
}
int main(){
    fastIO
    test solve();
    return 0;
}