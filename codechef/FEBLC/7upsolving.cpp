//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
ll sf[100001]={};
void sieve(){
    for(ll i=2;i<=100000;i++){
        if(!sf[i]){
            for(ll j=i;j<=100000;j+=i)
                sf[j]=i;
        }
    }
}
void dfs(vector<array<ll, 2> > &pf,vector<ll> &f, ll i=0, ll x=1){
    if(i>=pf.size()||x*pf[i][0]>100000){
        f.push_back(x);
        return;
    }
    for(ll j=0;j<=2*pf[i][1]&&x<=100000;x*=pf[i][0],j++) //*2 as these were factors of x or y
        dfs(pf,f,i+1,x);
}
ll ans=0;
void solve2(ll n, ll x[], ll m, ll y[]){
    ll c[2][100001]={};
    f(i,0,m)
        c[y[i]<0][abs(y[i])]++;
    f(i,0,n){
        vector<array<ll, 2> > pf;
        ll num=abs(x[i]);
        while(num>1){
            ll c=0,p=sf[num];
            while(num%p==0){
                num/=p;
                c++;
            }
            pf.push_back({p,c});
        }
        reverse(pf.begin(),pf.end());
        vector<ll> f; //stores factor of x[i]*x[i]
        dfs(pf,f);
        for(ll j:f){
            if((ll)x[i]*x[i]/j<=100000)
                ans+=c[0][j]*c[1][(ll)x[i]*x[i]/j];
        }
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    ll x[n],y[m];
    bool zeros=false;
    f(i,0,n){
        cin>>x[i];
        if(!x[i])
        {
            zeros=true;
            i--;
            n--;
        }
    }
    f(i,0,m){
        cin>>y[i];
        if(!y[i])
        {
            zeros=true;
            i--;
            m--;
        }
    }
    ans=(1LL)*zeros*n*m;
    solve2(n,x,m,y);
    solve2(m,y,n,x);
    cout<<ans<<"\n";
}

int main(){
    fastIO
    sieve();
    test solve();
    return 0;
}