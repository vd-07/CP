#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,flag=1;
		cin>>n;
		long long int a[n],sum=0,contsum=0,res=INT_MIN;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
				
		}
		for(int i=0;i<n-1;i++){
			contsum+=a[i];
				res=max(res,contsum);
			if(contsum<=0)
					contsum=0;
		}
		contsum=0;
		for(int i=1;i<n;i++){
			contsum+=a[i];
			res=max(res,contsum);
			if(contsum<0)
				contsum=0;
		}
		if(sum>res)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}