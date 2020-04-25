//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test ll t;cin>>t;while(t--)
#define mod 1000000007
#define FILL(x,y) memset(x,y,sizeof(x))
typedef pair<int,int> pii;
typedef pair<int, pii> node;

string s;
int n;
int t[5000000]={}, o[5000000]={} , c[5000000]={};
void build(int id=1, int l=0, int r=n){
    if(r-l<1){
        if(s[l]=='(')
            o[id]++;
        else
            c[id]++;
        return;
    }
    int mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    int tmp=min(o[2*id],c[2*id+1]);
    t[id]=t[2*id]+t[2*id+1]+tmp;
    o[id]=o[2*id]+o[2*id+1]-tmp;
    c[id]=c[2*id]+c[2*id+1]-tmp;
    // cout<<"Node : "<<id<<"\n";
    // cout<<"Open Brackets : "<<o[id]<<" Closed Brackets : "<<c[id]<<"\n";
}

node segment(int x, int y, int id=1, int l=0, int r=n){
    if(l>y||x>r) return node(0,pii(0,0));
    if(x<=l&&r<=y) return node(t[id],pii(o[id],c[id]));
    int mid=(l+r)/2;
    node a = segment(x,y,2*id,l,mid), b = segment(x,y,2*id+1,mid+1,r);
    int T, temp, O, C;
    temp=min(a.second.first, b.second.second);
    T=a.first+b.first+temp;
    O=a.second.first+b.second.first - temp;
    C=a.second.second+b.second.second-temp;
    return node(T,pii(O,C));
}

int main(){
    fastIO
    cin>>s;
    n=(int)s.size()-1;
    build();
    int x,y,q;
    cin>>q;
    while(q--){
        cin>>x>>y;
        node ans=segment(x-1,y-1);
        // cout<<2*ans.first<<" "<<ans.second.first<<" "<<ans.second.second<<"\n";
        cout<<2*ans.first<<"\n";
    }

    return 0;
}

