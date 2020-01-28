#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int comp=0,odd=0,even=0;
	for(int i=0;i<n-1;i++){
		if(a[i]&1)
			odd++;
		else if(a[i])
			even++;
		if(((a[i]&1)^(a[i+1]&1))&&a[i]!=0)
			comp++;
	}
	odd=(n+1)/2-odd;
	even=n/2-even;

	return 0;
}