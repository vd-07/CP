#include <iostream>
#include <math.h>
using namespace std;
typedef  long long int ll;
#define mod 1000000007
int main(){
	int t;
	cin>>t;
	while(t--){
		ll l,r,temp;
		cin>>l>>r;
		ll sum=0;temp=l;
		ll m=(1<<((int)(log2(l)+0.5)-1));
		ll p=(1<<((int)(log2(l)+0.5)));
		ll s=(1<<((int)(log2(l)+0.5)+1));
		if(p>l){
			if(l&1)
			sum=(sum+l+m*(p-l-1))%mod;
		else
			sum=(sum+2*l+m*(p-l-2))%mod;	
		}
		sum=(sum+(p*(s-p))%mod)%mod;
		cout<<sum<<"\n";
	}
	return 0;
}