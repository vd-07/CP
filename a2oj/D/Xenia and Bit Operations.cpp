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
#define test ll t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
ll n,m;
struct SegmentTreeNode {
ll curr;
void assignLeaf(int value) {
    curr = value;
  }
void merge(SegmentTreeNode& left, SegmentTreeNode& right, ll level) {
    if((level&1)==(n&1))
    curr=(left.curr)|(right.curr);
    else
    curr=(left.curr)^(right.curr);
  }
ll getValue() {
return curr;
  }
};

//Segment Tree Template from : https://gist.github.com/kartikkukreja/2e7685e1fc8dbca0001b#file-segment-tree-template-cpp
// T is the type of input array elements
// V is the type of required aggregate statistic
template<class T, class V>
class SegmentTree {
  SegmentTreeNode* nodes;
  int N;

public:
  SegmentTree(T arr[], int N) {
    this->N = N;
    nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
    buildTree(arr, 1, 0, N-1);
  }
  
  ~SegmentTree() {
    delete[] nodes;
  }
  
  V getValue(int lo, int hi) {
    SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
    return result.getValue();
  }
  
  void update(int index, T value) {
    update(1, 0, N-1, index, value);
  }
  
  private:	
  void buildTree(T arr[], int stIndex, int lo, int hi, ll level=1) {
    if (lo == hi) {
      nodes[stIndex].assignLeaf(arr[lo]);
      return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    buildTree(arr, left, lo, mid, level+1);
    buildTree(arr, right, mid + 1, hi, level+1);
    nodes[stIndex].merge(nodes[left], nodes[right], level);
  }
  
  SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi, int level=1) {
    if (left == lo && right == hi)
      return nodes[stIndex];
    	
    int mid = (left + right) / 2;
    if (lo > mid)
      return getValue(2*stIndex+1, mid+1, right, lo, hi);
    if (hi <= mid)
      return getValue(2*stIndex, left, mid, lo, hi);
    	
    SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid, level+1);
    SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi,level+1);
    SegmentTreeNode result;
    result.merge(leftResult, rightResult, level);
    return result;
  }
  
  int getSegmentTreeSize(int N) {
    int size = 1;
    for (; size < N; size <<= 1);
    return size << 1;
  }
  
  void update(int stIndex, int lo, int hi, int index, T value, ll level=1) {
    if (lo == hi) {
    nodes[stIndex].assignLeaf(value);
    return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid)
      update(left, lo, mid, index, value, level+1);
    else
      update(right, mid+1, hi, index, value, level+1);
    
    nodes[stIndex].merge(nodes[left], nodes[right], level);
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
int modInverse(int n, int p) 
{ 
    return power(n, p-2, p); 
}

int main(){
	cin>>n>>m;
    READA(a,1<<n);
    SegmentTree<ll, ll> st(a,1<<n);
    // cout<<st.getValue(0,(1<<n)-1)<<" ";
    while(m--){
      READ2(p,b);
      st.update(p-1,b);
      cout<<st.getValue(0,(1<<n)-1)<<"\n";
    }
    return 0;
}