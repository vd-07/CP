#include <iostream>
 #include<math.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n],hash[1000001]={};
	for(int i=0;i<n;i++)
		{
			cin>>a[i];
			hash[a[i]]=1;
		}
	sort(a,a+n);
	int res=0;
	for(int i=n-1;i>=0;i--){
		if(i!=0&&a[i]==a[i-1])
			continue;
		for(int j=2*a[i];j<=a[n-1]+a[i];j+=a[i]){
			int index=lower_bound(a,a+n,j)-a;
			res=max(res,a[index-1]%a[i]);
		}

	}
	cout<<res;
	return 0;

}
