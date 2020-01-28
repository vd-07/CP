#include <iostream>

using namespace std;

int main(){
	int t,n,temp;
	long long sum,x;
	cin>>t;
	while(t--){
		cin>>n;
		sum=0,x=0;
		while(n--){
			cin>>temp;
			sum+=temp;
			x^=temp;
		}
		cout<<"2\n";
		cout<<x<<" "<<x+sum<<"\n";
	}
	return 0;
}