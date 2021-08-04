#include <iostream>
using namespace std;

int main(){
	int n;
	string a,b;
	cin>>n;
	cin>>a>>b;
	long long int c00=0,c01=0,c10=0,c11=0;
	for(int i=0;i<n;i++){
		if(a[i]=='0'&&b[i]=='0')
			c00++;
		else if(a[i]=='0'&&b[i]=='1')
			c01++;
		else if(a[i]=='1'&&b[i]=='0')
			c10++;
		else
			c11++;
	}
	cout<<(c00*c11+c00*c10+c01*c10);
	return 0;
}