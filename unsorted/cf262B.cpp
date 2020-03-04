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
ll toNum(ll num){
ll res=0;
while(num){
	res+=(num%10);
	num/=10;
}
return res;
}
ll powa(ll i, ll exp){
	ll res=1;
	f(j,0,exp){
		res*=i;
	}
	return res;
}
int main(){
		ll a,b,c;
		cin>>a>>b>>c;
		vector<ll> v;
		f(i,1,82){
			if(i==toNum(b*(powa(i,a))+c)&&((b*(powa(i,a))+c)<1000000000))
			{
				v.push_back(b*(powa(i,a))+c);
			}
		}
		cout<<v.size()<<"\n";
		f(i,0,v.size()){
			cout<<v[i]<<" ";
		}
		return 0;
}
