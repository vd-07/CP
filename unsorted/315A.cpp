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
int main(){
	int n,a,b;
	cin>>n;
	vector<pair<int , int> > v;int temp=n;
	while(n--){
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	int ct=0;
	for(auto itr=v.begin();itr!=v.end();itr++){
		for(auto ptr=v.begin();ptr!=v.end();ptr++){
			if(itr!=ptr&&itr->first==ptr->second){
				ct++;
				break;
			}
		}
	}
	cout<<(temp-ct);
	return 0;
}