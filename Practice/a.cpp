
//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define uint unsigned long long int
#define READ(a) int a; cin>>a
#define sz(a) (int)((a).size())
#define READ2(a,b) int a,b; cin>>a>>b
#define READ3(a,b,c) int a,b,c; cin>>a>>b>>c
#define READ4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d
#define f(i, s, e) for(int i=s;i<e;i++)
#define READC(c) char c; cin>>c
#define READA(a,n) int a[n]; f(i,0,n) cin>>a[i]
#define READS(s) string s; cin>>s
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define int128 __int128
#define ff first
#define ss second
#define MAXN  200001
int a[MAXN];
struct SegmentTreeNode {
int left, right;
void assignLeaf(int value) {
	if(a[value] == 0)
		left = right = value;
	else 
		left = -1, right = -1;
  }
void merge(SegmentTreeNode& l, SegmentTreeNode& r) {
	if(l.left == -1 && r.left == -1)
	{
		left = -1;
		right = -1;
		return;
	}
	if(l.left == -1) {
		left = r.left;
		right = r.right;
		return;
	}
	if(r.left == -1) {
		left = l.left;
		right = r.right;
		return;
	}
	if(r.left == l.right + 1)
		left = l.left, right = r.right;
	else if(l.right - l.left > r.right - r.left)
		left = l.left, right = l.right;
	else if(l.right - l.left < r.right - r.left)
		left = r.left, right = r.right;
	else
		left = l.left, right = l.right;

  }
pair<int, int> getValue() {
	pair<int, int> p = {left, right};
    return p;
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
      nodes[stIndex].assignLeaf(lo);
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
	a[lo] = value;
    nodes[stIndex].assignLeaf(lo);
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

int power(int x, int y)
{ 
    int res = 1; 
    while (y > 0){ 
        if (y & 1) 
            res = (res*x);
        y = y>>1; 
        x = (x*x); 
    } 
    return res; 
} 
//int modInverse(int n, int p) 
//{ 
    //return power(n, p-2, p)%p; 
//}
int spf[MAXN];
void sieve() {
	spf[1] = 1;
	for(int i = 2; i < MAXN; i++) spf[i] = i;
	for(int i = 2; i * i < MAXN; i++) {
		if(spf[i] == i) {
			for(int j = i * i; j < MAXN; j+=i) {
				if(spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

void solve() {
	;
}

int32_t main(){
    solve();
	return 0;
}
