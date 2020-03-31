//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define READ(a) ll a; cin>>a
#define READ2(a,b) ll a,b; cin>>a>>b
#define f(i,s,e) for(int i=s;i<e;i++)
#define READC(c) char c; cin>>c
#define READA(a,n) ll a[n]; f(i,0,n) cin>>a[i]
#define READS(s) string s; cin>>s
#define FILL(x,y) memset(x,y,sizeof(x))
#define test ll t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define int128 __int128
// Guide on how to use 128 bit integer on g++
// __int128 v=2;
//     printf("%llu", v);

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1; 
    x = x % p;  
    while (y > 0){ 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res%p; 
} 
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p)%p; 
}
ll counts(ll num){
    ll ct =0;
    while(num) {
        if(num%2==1)
        ct++;
        num /= 2;
    }
    return ct;
}
vector<ll> bin(ll num) {
    vector<ll> s;
    while(num) {
        s.push_back(num%2);
        num /= 2;
    }
    return s;
}
void solve(){
    READ(n);
    READA(b,n);
    ll ans = 1;
    f(i, 0, n-1){
        // if(b[i]>b[i+1])
        // {
        //     cout<<0<<"\n";
        //     return;
        // }
        ans = (ans * power(2, counts(b[i]), mod)) % mod;
    }
    // ll hash[33];
    // memset(hash, 0ll, sizeof(hash));
    f(i,0,n-1) {
        if((b[i]&b[i+1]) != b[i]) {
            cout<<0<<"\n";
            return;
        }

    }
    cout<<(ans % mod)<<"\n";
}

int main(){
	test solve();
    return 0;
}