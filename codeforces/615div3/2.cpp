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
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007
typedef unsigned long long int ull;
#define f(i,s,n) for(int i=s;i<n;i++)
#define test ll t;cin<<t;while(t--)
#define pb push_back
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define abs(x) ((x < 0)?-(x):x)
#define scanr(a,n) for(ll i=0;i<n;i++){cin>>a[i];} 
#define v(a) vector<ll> a;
#define bitct(n) __builtin_popcount(n)
ll firstfactor=1;
ll fact(ll num){

	for(int i=2;i*i<=num;i++){
		if(num%i)
			continue;
		if(i!=firstfactor)
		return i;
	}
	return num;
}
void solve(){
	ll n;
	cin>>n;
	firstfactor=fact(n);
	if(firstfactor==n){
		cout<<"NO\n";
		return;
	}
	ll secondfactor=fact(n/firstfactor);
	if(secondfactor==firstfactor||(n/(firstfactor*secondfactor))==firstfactor||(n/(firstfactor*secondfactor))==secondfactor||secondfactor*firstfactor==n){
		cout<<"NO\n";
		return;	
	}
	cout<<"YES\n";
	cout<<firstfactor<<" "<<secondfactor<<" "<<(n/(firstfactor*secondfactor))<<"\n";
}
int main()
{
	fastIO
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}