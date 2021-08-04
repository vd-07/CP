#include <iostream>

using namespace std;

int main(){
	int n;
	while(cin>>n){
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int sum=0;
		for(int i=0;i<n-1;i++)
			sum+=(a[i]-a[i+1])>0?(a[i]-a[i+1]):(a[i+1]-a[i]);
		if(sum==(n*(n-1))/2)
			cout<<"Jolly\n";
		else
			cout<<"Not Jolly\n";
	}
	return 0;
}