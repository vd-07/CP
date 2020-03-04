#include <iostream>
#include <map>
using namespace std;

int main()
{
	string s,a;
	cin>>a;
	map<int,char> mp;
	for(int i=0;i<a.size();i++){
		if(mp[a[i]]==0)
			mp[a[i]]=i+'a';
	}
	cin>>s;
	
	for(int i=0;i<s.size();i++){
		cout<<mp[s[i]];
	}
	return 0;
}