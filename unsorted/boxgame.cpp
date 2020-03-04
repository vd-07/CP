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
#define f(i,start,end) for(int i=start;i<end;i++)
#define MOD 1000000007
int main() {
	int t,n,k,p;
	cin>>t;
	while(t--){
		cin>>n>>k>>p;
		int a[n], maxi=INT_MIN,mini=INT_MAX,maxi1=INT_MIN,mini1=INT_MAX;
		f(i,0,n){
			cin>>a[i];
			maxi=max(maxi,a[i]);
			mini=min(mini,a[i]);

		}
		f(i,0,n){
			if(a[i]<maxi)
				maxi1=max(maxi1,a[i]);
			if(a[i]>mini)
				mini1=min(mini1,a[i]);
		}
		int maxi2=INT_MIN,mini2=INT_MAX;
		f(i,0,n){
			if(a[i]<maxi1)
				maxi2=max(maxi2,a[i]);
			if(a[i]>mini1)
				mini2=min(mini2,a[i]);
		}
		if(p==0){
			if((k&1)==0){
				if(a[n-1]==maxi||a[0]==maxi){
					if(a[0]==maxi1||a[n-1]==maxi1)
						cout<<maxi2<<"\n";
					else
						cout<<maxi1<<"\n";
				}
			}
			else
				cout<<maxi<<"\n";
		}
		else{
			if((k&1)==0){
				if(a[n-1]==mini||a[0]==mini){
					if(a[0]==mini1||a[n-1]==mini1)
						cout<<mini2<<"\n";
					else
						cout<<mini1<<"\n";
				}
			}
			else
				cout<<mini<<"\n";
		}
		
	}
	
	return 0;
}
