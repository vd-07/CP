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
#define mp make_pair


struct SegmentTreeNode {
int maxNum, secondMaxNum;
void assignLeaf(int value) {
    maxNum=value;
    secondMaxNum=-1;
  }
void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
    maxNum=max(left.maxNum, right.maxNum);
    secondMaxNum=min(max(left.maxNum, right.secondMaxNum), max(left.secondMaxNum, right.maxNum));
  }
int getValue() {
    return maxNum+secondMaxNum;
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
  void buildTree(T arr[], int stIndex, int lo, int hi) {
    if (lo == hi) {
      nodes[stIndex].assignLeaf(arr[lo]);
      return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    buildTree(arr, left, lo, mid);
    buildTree(arr, right, mid + 1, hi);
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
  
  SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
    if (left == lo && right == hi)
      return nodes[stIndex];
    	
    int mid = (left + right) / 2;
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
  
  int getSegmentTreeSize(int N) {
    int size = 1;
    for (; size < N; size <<= 1);
    return size << 1;
  }
  
  void update(int stIndex, int lo, int hi, int index, T value) {
    if (lo == hi) {
    nodes[stIndex].assignLeaf(value);
    return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
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
    int r0,c0;
    cin>>r0>>c0;
    vector<pii> moves;
    moves.pb(mp(r0,c0));
    ll curx=r0,cury=c0;
    if(r0!=c0){
        curx=(r0+c0)/2;
        cury=curx;
        moves.pb(mp(curx,cury));
    }
    moves.pb(mp(1,1));
    moves.pb(mp(2,2));
    moves.pb(mp(1,3));
    moves.pb(mp(3,1));
    moves.pb(mp(2,2));
    moves.pb(mp(3,3));
    moves.pb(mp(1,5));
    moves.pb(mp(5,1));
    moves.pb(mp(3,3));
    moves.pb(mp(4,4));
    moves.pb(mp(1,7));
    moves.pb(mp(7,1));
    moves.pb(mp(4,4));
    moves.pb(mp(5,5));
    moves.pb(mp(8,2));
    moves.pb(mp(2,8));
    moves.pb(mp(5,5));
    moves.pb(mp(6,6));
    moves.pb(mp(8,4));
    moves.pb(mp(4,8));
    moves.pb(mp(6,6));
    moves.pb(mp(7,7));
    moves.pb(mp(8,6));
    moves.pb(mp(6,8));
    moves.pb(mp(7,7));
    moves.pb(mp(8,8));
    cout<<moves.size()<<'\n';
    for(auto e:moves){
        cout<<e.first<<" "<<e.second<<'\n';
    }
}

int main(){
    fastIO;
	test solve();
    return 0;
}