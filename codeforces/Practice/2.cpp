#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define loop(i,a,b) for(ll i = (ll)a ; i < (ll)b ; i++)
#define rtloop(i,a,b) for(ll i = (ll)a; i >= (ll)b; i--)
#define pb push_back
#define mp make_pair
#define yo(a) cerr <<#a <<" = " << a <<"\n";
const ll mod = ((1e9) + 7);



void solve(){
    ll n;
    cin >> n;
    ll a[n];
    loop(i,0,n)cin >> a[i];
    ll it = 0;
    ll curr, sum = 0;
    while(it != n){
        if(a[it] > 0){curr = a[it];
            while(a[it] > 0 && it != n){
                curr = max(curr, a[it]);
                it ++;
            }
            sum += curr;
        }
        if(a[it] < 0){
            curr = a[it];
            while(a[it] < 0 && it != n){
                curr = max(curr, a[it]);
                it++;
            }
            sum += curr;
        }
    }
    cout << sum <<"\n";







}







int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t;
    cin >> t;
    loop(i,1,t+1){
        solve();
    }
        


    return 0;
}


