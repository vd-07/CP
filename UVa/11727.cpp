#include <bits/stdc++.h>
using namespace std;
 
 int main(){
 	int t,s1,s2,s3;
 	cin>>t;
 	for(int i=1;i<=t;i++){
 		cin>>s1>>s2>>s3;
 		int arr[]={s1,s2,s3};
 		sort(arr,arr+3);
 		cout<<"Case "<<i<<": "<<arr[1]<<"\n";
 	}
 	return 0;
 }