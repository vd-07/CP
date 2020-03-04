#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	int maxicon=0,temp=1,exec=0;
	for (int i = 1; i < a.size(); ++i)
	{
		if(a[i]>a[i-1]){

			temp++;
			exec=0;
		}
		
		else
		{
			if(i!=a.size()-1&&exec!=1){
				if(a[i]<a[i+1]){
							a.erase(a.begin()+i-1);
							i-=2;
							temp--;
				}
				else{
					a.erase(a.begin()+i);
					i--;
				}	
				exec=1;
				continue;
			}
			if(maxicon<temp)
				maxicon=temp;
			temp=1;
		}
	}
	cout<<maxicon;
	// int prevind=0,prev=0,prevmax=0,temp=1,maxcon=0;
	// for(int i=1;i<n;i++){
	// 	if(a[i-1]<a[i]){
	// 		if(prevind+3==i&&a[i-1]>prev)
	// 			temp+=prevmax;
	// 		temp++;
			
	// 	}
	// 	else
	// 	{
			
	// 		if(maxcon<temp)
	// 			maxcon=temp;
	// 		if(temp!=1){
	// 			prevind=i-1;
	// 			prev=a[i-1];
	// 			prevmax=temp;
	// 		}
	// 		temp=1;
	// 	}
	// 	cout<<"prev "<<a[i-1]<<" curr "<<a[i]<<"curr count "<<temp<<"prev index "<<prevind<<"prevmax "<<prevmax<<"prev val "<<prev<<endl;
	// }	
	// if(maxcon<temp)
	// 	maxcon=temp;
	
	// cout<<maxcon;
	return 0;
}