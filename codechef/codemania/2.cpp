#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
	fastIO
	int n;
	cin>>n;
    ll a[n+1];
    ll sum[11][n+1];
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	}
	for(int i=1;i<=10;i++)
	{
	    for(int j=1;j<=i;j++)
	    {
	        sum[i][j]=a[j];
	    }
	    for(int j=i+1;j<=n;j++)
	    {
	        sum[i][j]=a[j]+sum[i][j-i];
	    }
	}
	int q,l,r,d;
	cin>>q;
	while(q--)
	{
	    
	    cin>>l>>r>>d;
	    if((r-((r-l)/d+1)*d)<=0)
	        cout<<sum[d][r]<<"\n";
	    else
	    
	        cout<<(sum[d][r]-sum[d][(r-((r-l)/d+1)*d)])<<"\n";
	}
	return 0;
}
