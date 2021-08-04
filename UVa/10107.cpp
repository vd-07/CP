#include <iostream>
#include <set>
using namespace std;

int main(){
	int temp;
	set<int> s;
	while(cin>>temp){
		s.insert(temp);
		temp=s.size();
		if(temp==1)
			cout<<(*s.begin())<<"\n";
		else if(temp&1){
			cout<<(*next(s.begin(),(temp+1)/2))<<"\n";
		}
		else
			cout<<((*next(s.begin(),temp/2))+(*next(s.begin(),temp/2+1)))/2<<"\n";
	}
	return 0;
}