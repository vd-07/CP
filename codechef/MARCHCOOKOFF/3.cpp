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
ll choice;
struct SegmentTreeNode {
ll prefixMaxSum, suffixMaxSum, sum;
void assignLeaf(ll value) {
    prefixMaxSum = suffixMaxSum = sum = value;
  }
void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
    sum = left.sum + right.sum;
    prefixMaxSum = max(left.prefixMaxSum, left.sum + right.prefixMaxSum);
    suffixMaxSum = max(right.suffixMaxSum, right.sum + left.suffixMaxSum);
  }
ll getValue() {
if(choice == 1)
return sum;
if(choice == 2)
return prefixMaxSum;
return suffixMaxSum;
  }
};
//Segment Tree Template from : https://gist.github.com/kartikkukreja/2e7685e1fc8dbca0001b#file-segment-tree-template-cpp
// T is the type of input array elements
// V is the type of required aggregate statistic
template<class T, class V>
class SegmentTree {
  SegmentTreeNode* nodes;
  ll N;

public:
  SegmentTree(T arr[], ll N) {
    this->N = N;
    nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
    buildTree(arr, 1, 0, N-1);
  }
  
  ~SegmentTree() {
    delete[] nodes;
  }
  
  V getValue(ll lo, ll hi) {
    SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
    return result.getValue();
  }
  
  void update(ll index, T value) {
    update(1, 0, N-1, index, value);
  }
  
  private:	
  void buildTree(T arr[], ll stIndex, ll lo, ll hi) {
    if (lo == hi) {
      nodes[stIndex].assignLeaf(arr[lo]);
      return;
    }
    
    ll left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    buildTree(arr, left, lo, mid);
    buildTree(arr, right, mid + 1, hi);
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
  
  SegmentTreeNode getValue(ll stIndex, ll left, ll right, ll lo, ll hi) {
    if (left == lo && right == hi)
      return nodes[stIndex];
    	
    ll mid = (left + right) / 2;
    if (lo > mid)
      return getValue(2*stIndex+1, mid+1, right, lo, hi);
    if (hi <= mid)
      return getValue(2*stIndex, left, mid, lo, hi);
    	
    SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
    SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
    SegmentTreeNode result;
    result.merge(leftResult, rightResult);
    return result;
  }
  
  ll getSegmentTreeSize(ll N) {
    ll size = 1;
    for (; size < N; size <<= 1);
    return size << 1;
  }
  
  void update(ll stIndex, ll lo, ll hi, ll index, T value) {
    if (lo == hi) {
    nodes[stIndex].assignLeaf(value);
    return;
    }
    
    ll left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid)
      update(left, lo, mid, index, value);
    else
      update(right, mid+1, hi, index, value);
    
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
};

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
    return res; 
} 
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p)%p; 
}

void solve(){
    READ2(n,q);
    READA(a,n);
    SegmentTree<ll, ll> st(a,n);
    
    while(q--) {
        char U;
        cin>>U; READ2(x,y);
        if(U == 'Q') {

            ll ans = 0;
            if(x>1) {
                choice = 3;
                ans = max(ans,st.getValue(0,x-2));
            }
            
            if(y<n) {
                choice = 2;
                ans = max(ans, ans+st.getValue(y,n-1));
            }
            choice = 1;
            ans += st.getValue(x-1,y-1);
            cout<<ans<<"\n";
        }
        else
        {
            a[x-1]=y;
            st.update(x-1,y);
        }
        
    }

}

int main(){
	test solve();
    return 0;
}