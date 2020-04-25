#include <iostream>

using namespace std;

int main(){
	int t,n,p,q,temp;
	long long sum,x;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n]; temp=0;
		cin>>a[0];
		for(int i=1;i<n;i++){
			cin>>a[i];
			if(temp==0&&abs(a[i]-a[i-1])>1)
			{
				temp=1;
				cout<<"YES\n";
				cout<<i<<" "<<i+1<<"\n";
			}
		}
		if(!temp)
			cout<<"NO\n";
	}
	return 0;
}