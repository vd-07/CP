//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define f(i,s,e) for(int i=s;i<e;i++)
#define READA(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define READ(x) cin>>x;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test ll t;cin>>t;while(t--)
#define mod 1000000007
#define FILL(x,y) memset(x,y,sizeof(x))
typedef pair<int,int> pii;
#define MAX 1000000
int a[MAX+1], seg[4*MAX+16];
void build(int node, int l, int r) {
    if(r-l<1){
        seg[node]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    seg[node]=min(seg[node*2],seg[node*2+1]);    
}
int query(int node, int l, int r, int s, int e){
    if(s>=l&&e<=r)
        return seg[node];
    if(s>r||e<l)
        return INT_MAX;
    int mid=(s+e)/2, a=INT_MAX, b=INT_MAX;
    // if(s>=l&&mid<=r)
    a=query(node*2, l, r, s, mid);
    // if(e<=r&&mid>=l)
    b=query(node*2+1,l,r,mid+1,e);
    // cout<<a<<" "<<b<<endl;
    return min(a,b);
}

int main(){
    // FILL(a,INT_MAX);
    fastIO
    int n;
    cin>>n;
    READA(a,n);
    build(1,0,n-1);
    int q,l,r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        int ans=query(1,l-1,r-1,0,n-1);
        cout<<ans<<"\n";
    }
    // int p=2;
    // cout<<seg[1]<<"\n";

    // cout<<seg[2]<<" "<<seg[3]<<"\n";
    // cout<<seg[4]<<" "<<seg[6]<<"\n";
    // cout<<seg[8]<<" "<<seg[5]<<" "<<seg[12]<<" "<<seg[7]<<"\n";
    // cout<<seg[16]<<" "<<seg[17]<<" "<<seg[9]<<" "<<seg[10]<<" "<<seg[11]<<" "<<seg[24]<<" "<<seg[25]<<" "<<seg[13]<<" "<<seg[14]<<" "<<seg[15]<<"\n";
    return 0;
}

