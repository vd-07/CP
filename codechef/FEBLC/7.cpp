//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
ll t1,t2; 
vector<vector<pair<ll,ll> > > factors(100001);
 
void fac(){
    for(ll i=1;i<=100000;i++){
        vector<ll> temp;
        for(ll j=1;j*j<=i;j++){
            if(i%j)
            continue;
            temp.push_back(j);
            temp.push_back(i/j);
        }
        int a[100001]={};
        for(ll j=0;j<temp.size();j++){
            for(ll k=0;k<temp.size();k++){
                t1=temp[j]*temp[k];
                if((i*i)%t1==0){
                    t2=(i*i)/t1;
                    if(t1<t2)
                    swap(t1,t2);
                    if(t1>100000||a[t1])
                    continue;
                    factors[i].push_back({t1,t2});
                    a[t1]=1;
                }
                // cout<<t1<<" "<<t2<<"\n";
            }
        }
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    ll x[n],y[m];
    int mppx[100001]={},mppy[100001]={},mpnx[100001]={},mpny[100001]={};
    ll x0=0,y0=0;
    f(i,0,n) {cin>>x[i];x[i]>0?mppx[x[i]]=1:mpnx[-x[i]]=1;if(x[i]==0) x0=1;}
    f(i,0,m) {cin>>y[i];y[i]>0?mppy[y[i]]=1:mpny[-y[i]]=1;if(y[i]==0) y0=1;}
    ll ans=0,ax[100001],ay[100001];
    memset(ax,-1,sizeof(ax));
    memset(ay,-1,sizeof(ay));

    f(i,0,n){
        x[i]=abs(x[i]);
        //factors
        ll ct=0;
        if(ax[x[i]]!=-1)
        {
            ans+=ax[x[i]];
            continue;
        }
        for(auto e:factors[x[i]]){
            // if(y[i]==1)
            // cout<<e.first<<" "<<e.second<<"\n";
            t1=e.first,t2=e.second;
            if(mppy[t1]==1&&mpny[t2]==1)
                ct++;
            if(t1!=t2&&mpny[t1]==1&&mppy[t2]==1)
                ct++;
        }
        ans+=ct;
        ax[x[i]]=ct;
    }
    // cout<<ans<<"\n"; 
    f(i,0,m){
        y[i]=abs(y[i]);
        //factors
        ll ct=0;
        if(ay[y[i]]!=-1)
        {
            ans+=ay[y[i]];
            continue;
        }
        for(auto e:factors[y[i]]){
            // if(y[i]==1)
            // cout<<e.first<<" "<<e.second<<"\n";
            t1=e.first,t2=e.second;
            if(mppx[t1]==1&&mpnx[t2]==1)
                ct++;
            if(t1!=t2&&mpnx[t1]==1&&mppx[t2]==1)
                ct++;
        }
        ans+=ct;
        ay[y[i]]=ct;
    }
    if(x0==1)
    ans+=(m)*(n-1);
    if(y0==1)
    ans+=(m-1)*(n);
    cout<<ans<<"\n";
}

int main(){
    fastIO
    fac();
    test solve();
    return 0;
}