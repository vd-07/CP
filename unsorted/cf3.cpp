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
	int t,m,n;
	cin>>t;
	while(t--){
		cin>>n>>m;
		ll a[n];
		f(i,0,n){
			cin>>a[i];
		}
		vector<vector<ll> > v(m);
		for(int i=0;i<m;i++){
			for(int j=i;j<n;j+=m){
				v[i].push_back(a[j]);
			}
		}
		sort(v.begin(),v.end());
		set<pair<ll,ll> > s;
		ll pos[m]={},posti;
		for(int i=0;i<m;i++){
			s.insert(make_pair(v[i][0],i));
			pos[i]=0;
		}
		// for(auto jkr=s.begin();jkr!=s.end();jkr++){
		// 	cout<<(jkr->first)<<" "<<(jkr->second)<<endl;
		// }
		while(1)
		{
			// auto itr=find(v[(s.begin())->second].begin(),v[(s.begin())->second].end(),(s.begin())->first);
			posti=s.begin()->second;
			// cout<<((v[posti].end()-v[posti].begin()))<<endl;
			if(++pos[posti]!=(v[posti].end()-v[posti].begin())){
				s.insert(make_pair(v[posti][pos[posti]],posti));
			s.erase(s.begin());
			}
			else break;
		}

		auto itr=s.begin(),ptr=s.end();
		cout<<((--ptr)->first-itr->first)<<"\n";

	}
	return 0;
}
