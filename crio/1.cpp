//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define pii pair<int, int>
int lines(char c){
    switch(c){
        case '0' : return 2;
        case '1' : return 2;
        case '2' : return -1;
        case '3' : return -1;
        case '4' : return 2;
        case '5' : return -1;
        case '6' : return 0;
        case '7' : return 1;
        case '8' : return 1;
        case '9' : return 0;
    }
    return 0;
}
//const ll n=1000001;

void solve(){
    string s;
    cin>>s;
    ll res=0;
    for(auto e:s){
        res+=lines(e);
    }
    cout<<res<<"\n";
}

int main(){
    fastIO
    test solve();
    return 0;
}