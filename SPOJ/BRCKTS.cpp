//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define READ(a) ll a; cin>>a
#define READ2(a,b) ll a,b; cin>>a>>b
#define f(i,s,e) for(int i=s;i<e;i++)
#define READA(a,n) ll a[n]; f(i,0,n) cin>>a[i]
#define READS(s) string s; cin>>s
#define test ll t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 

struct SegmentTreeNode {
int unmatchedOpenParans, unmatchedClosedParans;
void assignLeaf(char paranthesis) {
    if(paranthesis == '(')
        unmatchedOpenParans=1, unmatchedClosedParans=0;
    else
        unmatchedClosedParans=1, unmatchedOpenParans=0;
  }
void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
    int newMatches = min(left.unmatchedOpenParans, right.unmatchedClosedParans);
    unmatchedClosedParans = left.unmatchedClosedParans+right.unmatchedClosedParans-newMatches;
    unmatchedOpenParans=right.unmatchedOpenParans+left.unmatchedOpenParans-newMatches;
  }
bool getValue() {
return unmatchedOpenParans==0&&unmatchedClosedParans==0;
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
void solve(){
    READ(n);
    char s[30005];
    f(i,0,n) cin>>s[i];
    READ(m);
    SegmentTree<char , bool> st(s, n);
    f(i,0,m){
        READ(k);
        if(!k){
            if(st.getValue(0,n-1))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
        {
            s[k-1]=(s[k-1]=='(')?')':'(';
            st.update((int)k-1,s[k-1]);
        }
        
    }
}


int main(){
    fastIO
	ll t=10;
    // cout<<"vd";
     f(i,0,t){
        cout<<"Test "<<i+1<<":\n";
        solve();
    }
    return 0;
}