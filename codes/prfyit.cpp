#define stm clock_t cccc=clock();
#define ptm cout<<1.*(clock()-cccc)/CLOCKS_PER_SEC<<endl;

#include <algorithm>
#include <cassert>
#include <bitset>
#include <climits>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007



int main(){
	fastIO
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;

		int pos[s.size()+1]={},ct=0,maxct=0;
		for(int i=1;i<s.size();i++){
			pos[ct]++;
			if(s[i]!=s[i-1])
				ct++;
		}
		if(s.size()==ct+1)
			pos[ct]=1;
		calc(pos,s.size());
		// for(int i=0;i+3<s.size();i++){
		// 	if(pos[i]==0)
		// 		break;
		// 	// if(pos[i]==min(pos[i],min(pos[i+1],min(pos[i+2],pos[i+3]))))
		// 	maxct+=min(pos[i],min(pos[i+1],min(pos[i+2],pos[i+3])));
		// 	if(i==0&&pos[i]==min(pos[i],min(pos[i+1],min(pos[i+2],pos[i+3]))))
		// 		continue;
		// 	else
		// 	{
		// 		if(pos[i]==min(pos[i],min(pos[i+1],min(pos[i+2],pos[i+3]))))
		// 		{
		// 			pos[i+1]=pos[i+1]+pos[i-1];
		// 		}
		// 		else if(pos[i+1]==min(pos[i],min(pos[i+1],min(pos[i+2],pos[i+3]))))
		// 		{
		// 			pos[i+2]=pos[i+2]+pos[i];
		// 			i++;
		// 		}
		// 		else if(pos[i+2]==min(pos[i],min(pos[i+1],min(pos[i+2],pos[i+3]))))
		// 		{
		// 			pos[i+3]=pos[i+3]+pos[i+1];
		// 			pos[i+2]=pos[i];
		// 			i++;
		// 		}
		// 		else
		// 		{
		// 			if(i!=s.size()-1)
		// 			{
		// 				pos[i+4]=pos[i+4]+pos[i+2];
		// 				pos[i+3]=pos[i+1];
		// 				pos[i+2]=pos[i];
		// 				i++;
		// 			}
		// 		}
		// 	}
		// }
		// cout<<maxct<<"\n";
	}
	return 0;
	
}
