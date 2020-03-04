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
#define nl "\n"
#define MOD 1000000007

ll maxdigi(ll num){
    int maxi=num%10;
    num/=10;
	while(num){
	    if(maxi<num%10)
	    maxi=num%10;
	    num/=10;
	}
	return maxi;
}

int main(){
	fastIO
	ll n;
	cin>>n;
	ll ct=0;
	while(n>0){
		n-=maxdigi(n);
		ct++;
	}
	cout<<ct;
		return 0;
	
}
