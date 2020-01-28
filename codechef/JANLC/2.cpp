#include <iostream>

using namespace std;

int main(){
	unsigned long long N,A,B,C,D,E,S;
	int t,res;
	cin>>t;
	while(t--){
		cin>>N;
		cin>>A;
		S=1;
		while(N--)
			S*=10;
		
		cout<<(S*2+A)<<endl;
		cin>>B;
		C=S-B;
		cout<<C<<endl;
		cin>>D;
		E=S-D;
		cout<<E<<endl;
		cin>>res;
		if(res==-1)
			return 0;
	}
	return 0;
}