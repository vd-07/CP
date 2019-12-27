#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int temp=n;
		string s;
		cin>>s;
		map<char, vector<int> > mp;
		for(int i=0;i<s.size();i++)
			mp[s[i]].push_back(i);
		for(auto itr=mp.begin();itr!=mp.end();itr++){
			// cout<<itr->first<<endl;
			// for(int i=0;i<(itr->second.size());i++)
			// 	cout<<(itr->second[i])<<" ";
			// 		cout<<endl;
			
			for(int i=1;i<(itr->second.size());i++){
				if(temp>(itr->second[i])-(itr->second[i-1]))
					temp=(itr->second[i])-(itr->second[i-1]);
			}
		}
		cout<<(n-temp)<<"\n";
	}
	return 0;
}

