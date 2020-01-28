#include <iostream>
#include <map>

using namespace std;

int main(){
	int t;
	string s;
	cin>>t;
	while(t--){
		map<string,int> mp;
		long long int total=0;
		while(cin>>s)
			{
				mp[s]++;
				total++;
			}

		for(auto itr=mp.begin();itr!=mp.end();itr++){
			printf("%s %0.4f\n",(itr->first),100.0000*(itr->second)/total);
		}
		cout<<endl;

	}
	return 0;
}