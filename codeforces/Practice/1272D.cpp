#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int l[n],r[n],ans=1;
	l[0]=1;
	r[n-1]=1;
	for(int i=1;i<n;i++){
		if(a[i-1]<a[i])
			l[i]=l[i-1]+1;
		else 
			l[i]=1;
		ans=max(ans,l[i]);
	}
	for(int i=n-2;i>=0;i--){
		if(a[i]<a[i+1])
			r[i]=r[i+1]+1;
		else
			r[i]=1;
	}

	for(int i=1;i<n-1;i++){
		if(a[i-1]<a[i+1])
		ans=max(ans,r[i+1]+l[i-1]);
	}
	cout<<ans;
	return 0;

}