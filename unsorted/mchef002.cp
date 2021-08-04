#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	int n,flag;
	while(t--){
		cin>>n>>flag;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		int x,y,sum=0;
		for(int i=0;(a[i]<=flag)&&(i<n);i++){
			for(int j=i+1;(a[i]+a[j]<flag)&&(j<n);j++){
				if(a[i]+a[j]>sum){
					sum=a[i]+a[j];
					x=a[i];
					y=a[j];
				}
			}
		}
		cout<<x<<" "<<y<<"\n";
		
		
	}
	return 0;
}