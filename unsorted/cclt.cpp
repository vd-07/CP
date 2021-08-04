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
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007
int main() {
	fastIO
	int t;
	cin>>t;
	int x,y,z,n;
	while(t--){
		cin>>n;
		int a[n];
		f(i,0,n)
		cin>>a[i];
		sort(a,a+n);
		x=a[n/4];
		y=a[n/2];
		z=a[(n/4)*3];
		if((a[n/4-1]==a[n/4])||(a[n/2-1]==a[n/2])||(a[(n/4)*3-1]==a[(n/4)*3]))
			cout<<(-1)<<"\n";
		else
		cout<<x<<" "<<y<<" "<<z<<"\n";
		cout<<a[n/4-1]<<" "<<a[n/4]<<" "<<a[n/2-1]<<" "<<a[n/2]<<" "<<a[(n/4)*3-1]<<" "<<a[(n/4)*3]<<endl;
	}
	return 0;
	
	
}
