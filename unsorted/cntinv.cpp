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
typedef unsigned long long int ll;
//typedef long long int ll;
#define f(i,s,n) for(ll i=s;i<n;i++)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007
ll Multiplication(ll  a, 
                            ll  b
                            ) 
{ 
    ll  res = 0; 
  
    
    
  
    while (b) 
    { 
        
        if (b & 1) 
            res = (res + a); 
  
        
        a = (2 * a); 
  
        b >>= 1; 
    } 
  
    return res; 
} 
int main() {
	fastIO
	int t;
	ll n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		ll a[n],left=0,right=0;
		f(i,0,n)
		cin>>a[i];
		f(i,0,n){
			f(j,0,i){
				if(a[i]>a[j])
					left++;
			}
			f(k,i+1,n){
				if(a[i]>a[k])
					right++;
			}

		}
		ll ans=left*((k*(k-1))/2)+right*((k*(k+1))/2);
		cout<<ans<<"\n";
		}
	return 0;
	
	
}
