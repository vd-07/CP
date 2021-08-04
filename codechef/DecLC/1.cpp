#include <iostream>

using namespace std;

int main(){
	int t,count;
	cin>>t;
	string s,dub;
	while(t--){
		cin>>s;
		dub="";
		count=1;
		for(int i=1;i<s.size();i++){
			if(s[i]!=s[i-1])
			{
				dub+=s[i-1];
				dub+=count+'0';
				count=1;
			}
			else
				count++;
		}
		
			dub+=s[s.size()-1];
			dub+=(count+'0');
			if(dub.size()<s.size())
				cout<<"YES\n";
			else
				cout<<"NO\n";
		cout<<dub<<endl;
	}
	return 0;
}