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
typedef long long int ll;
int main(){
  ll n,k;
  cin>>n>>k;
  ll a[n],f[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>f[i];
  }
  sort(a,a+n);
  sort(f,f+n);
  int temp;
    for(int i=n-1;(i>=0)&&(k>0);i--){
      
      temp=a[i];
      if(a[i]<=k)
        a[i]=0;
      else
        a[i]-=k;
      k-=temp;
      
    }
    // for(int i=0;i<n;i++){
    //   cout<<a[i]<<" ";
    // }
    cout<<endl;
  ll res=0;
  sort(a,a+n);
  for(int i=0;i<n;i++){
    res=max(res,a[i]*f[n-i-1]);
  }
  cout<<res;
  
  return 0;
}