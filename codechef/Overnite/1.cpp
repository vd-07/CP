//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define test ll t;cin>>t;while(t--)
#define mod 1000000007
void solve(){ 

}

int main(){
    int n,temp;
    cin>>n;
    set<int> s;
    f(i,0,n){
        cin>>temp;
        s.insert(temp);
    }
    cout<<s.size()-1;
    return 0;
}