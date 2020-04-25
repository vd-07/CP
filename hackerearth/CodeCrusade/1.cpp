#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
long long arr[100005];

long long mexp(long long x,long long n)
{
    long long res=1;
    while(n>0)
    {
        if(n%2==1)
         res =(res*x)%m;
         x=(x*x)%m;
         n/=2;

    }
    return res;
}
long long mi(long long a)
{
    return mexp(a,m-2); 
}
int main()
{
    int n,i,q,l,r;
    long long x;

    cin>>n>>q>>x;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        arr[i]=(arr[i]*mexp(x,i-1))%m;
        arr[i]=(arr[i-1]+arr[i])%m;
    }

    while(q--)
    {
        cin>>l>>r;
        long long ans=((arr[r]-arr[l-1])*mi(mexp(x,l-1)))%m;
        cout<<ans<<"\n";

    }
    
}