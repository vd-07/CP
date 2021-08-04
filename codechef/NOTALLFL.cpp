//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define READA(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define READ(x) cin>>x;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test ll t;cin>>t;while(t--)
#define mod 1000000007
#define FILL(x,y) memset(x,y,sizeof(x))
typedef pair<int,int> pii;
#define MAX 1000000
ll tracker[1000001];
//I dont know how is this passing
void solve(){
    FILL(tracker,0);
    ll n,k;
    cin>>n>>k;
    ll count = 0, a[n], ans=1;
    READA(a,n);
    f(i,1,k){
        f(j,0,n){
            if(a[j]!=i)
                count++;
            else count=0;
        }
        ans=max(ans,count);
        if(count==n)
            break;
    }
    cout<<ans<<"\n";

}


int main(){
    fastIO
    test solve();
    return 0;
}