#include <bits/stdc++.h>
#include <map>

using namespace std;

int main() {
	int n, k, temp,m;
	char temp1;
	string s;
	cin >> n;
	while (n--) {
		cin >> k;
		map<char, int> mp;
		for (int i = 0; i < k; i++) {
			cin>>temp1>>temp;
			mp[temp1] = temp;
		}
		
// 		for(auto itr=mp.begin();itr!=mp.end();itr++)
// 		cout<<itr->first<<" "<<itr->second<<"\n";

		cin>>m;
		long long int sum=0;
		
// 		char t[10001];
        // cin.ignore();
        
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
		while(m--){
		    getline(cin,s);
		  //  while (s.size()==0 ) 
          //  getline(cin, s); 
		  //  cout<<s<<"\n";
		    for(int i=0;i<s.size();i++)
		    {
		        if(s[i]!=' ' && s[i]!='\n')
		        sum+=mp[s[i]];
		    }
		    
		}
// 		for(int i=0;i<10001;i++)
// 		cout<<t[i];
		printf("%0.2f$\n", sum/100.0);
	}
return 0;
}