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
	ll n;
	cin>>n;
	ll a[n];
	f(i,0,n)
	cin>>a[i];;
	sort(a,a+n);
	ll sum=0;
	f(i,0,n)
	sum+=abs(a[i]-(i+1));
	cout<<sum;
		return 0;
	


	
}
