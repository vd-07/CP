#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;
typedef long long int ll;
#define pb push_back

void getDivisors(ll n, vector<ll> &factors) 
{ 
    for (ll i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        {
            factors.pb(i);
            if (n/i != i)   factors.pb(n/i);
        }
    } 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,a,m;
    
    cin>>t;
    while(t--){
    	vector<ll> factors;
    	set<ll> arr;
        cin>>a>>m;
        getDivisors(m, factors);
        for(int i=0;i<factors.size();i++){
                if( factors[i] != 1 && factors[i]%a == 1){
                    arr.insert(((factors[i]-1)/a) * (m / factors[i]));  // Since factors are integers
            }
            
        }
        cout<<(arr.size())<<"\n";
        for (ll a : arr) cout << a << ' ';
    }
    return 0;
    }