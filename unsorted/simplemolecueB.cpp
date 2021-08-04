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
	int a,b,c;
	int lar=(a>b?(a>c?a:c):(b>c?b:c)),lar2=(a>b?(a>c?c:a):(b>c?c:b)),lar3=(a<b?(a<c?a:c):(b<c?b:c));
	if((a>b?(a>c?a:c):(b>c?b:c))<((a<b?(a<c?a:c):(b<c?b:c))+(a>b?(a>c?c:a):(b>c?c:b))))
	{
		if(lar==a)
			cout<<b<<" "<<0<<" "<<c;
		else if(lar==b)
			cout<<a<<" "<<b<<" "<<0;
		else
			cout<<0<<" "<<b<<" "<<a;
	}
	else if((a+b+c)%2==0&&lar<=lar2+lar3){
		if((a+b)%2==0)
			cout<<(a+b-c)/2<<" "<<b-(a+b-c)/2<<" "<<a-(a+b-c)/2;
		else if((b+c)%2==0)
			cout<<b-(c+b-a)/2<<" "<<(c+b-a)/2<<" "<<c-(c+b-a)/2;
		else
			cout<<a-(c+a-b)/2<<" "<<c-(c+a-b)/2<<" "<<(c+a-b)/2;
	}
	// stm 
	// ptm 
	return 0;
}
