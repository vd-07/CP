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
#define f(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
int main() {
	int n,m,temp1,temp2;
	cin>>n>>m;
	bool hd[n+1];
	memset(hd,false,sizeof(hd));
	f(i,0,m){
		cin>>temp2>>temp1;
		hd[temp1]=true;
		hd[temp2]=true;
	}
	f(i,1,n+1){
		if(hd[i]==false)
			{
				temp1=i;
				break;
			}
	}
	cout<<n-1<<"\n";
	f(i,1,n+1){

		if(temp1!=i)
			cout<<i<<" "<<temp1<<"\n";
	}

return 0;
	
}
