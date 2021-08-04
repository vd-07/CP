#include <iostream>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int temp,min=1000001;
		for (int i = 0; i < n; ++i)
		{
			cin>>temp;
			if(min>temp)
				min=temp;
		}
		cout<<min<<"\n";
	}
	return 0;
}