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
	int n;
	cin>>n;
	int a[n],ct=0;
	f(i,0,n)
	{
		cin>>a[i];
		if(a[i]==0)
			ct++;

	}
	int k=1;
	f(i,0,n){
		if(a[a[i]]==i)
			k=2;
	}
	if(ct==n)
		cout<<n;
	else
		cout<<(ct+k);

		return 0;
	


	
}
