#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(360%(180-n)==0){
			cout<<"YES\n";
			else
			cout<<"NO\n";
		}
	}
	return 0;
}