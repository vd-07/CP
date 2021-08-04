#include <iostream>

using namespace std;

int main(){
	int t,s,w1,w2,w3;
	cin>>t;
	while(t--){
		cin>>s>>w1>>w2>>w3;
		if(w1+w2+w3<=s)
			cout<<1<<endl;
		else if(w1+w2<=s||w2+w3<=s)
			cout<<2<<endl;
		else
			cout<<3<<endl;
	}
	return 0;
}