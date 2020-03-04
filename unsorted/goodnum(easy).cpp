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

int pow3(int num)
{
	int res=1,base=3;
	while(num){
		if(num&1)
		res=res*3;
		base*=base;
		num/=2;
	}
	return res;
}

int main() {
	int q;
	cin>>q;
	int n;
	while(q--){
		cin>>n;
		vector<int> fact;
		n++;
		while(n){
			int ct=0;
			n--;
			while(n%3==0){
				n/=3;
				ct++;
			}
			fact.push_back(ct);

		}
		sort(fact.begin(),fact.end());
		int num=(int)pow3(fact[0]);
		for(int i=1;i<fact.size();i++){
			if(fact[i]==fact[i-1])
				fact[i]++;
			num+=(int)pow3(fact[i]);
		}
		cout<<num<<"\n";
	}

return 0;
	
}
