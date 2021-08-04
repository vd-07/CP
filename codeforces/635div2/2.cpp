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
#define d1(a) cerr << #a << " " << a << endl;
#define d2(a, b) cerr << #a << " " << a << " " << #b << " " << b << endl;
#define d3(a, b, c) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << endl;
#define d4(a, b, c, d) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << " " << #d << " " << d << endl;
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
// Guide on how to use 128 bit integer on g++
// __int128 v=2;
//     printf("%intu", v);

//by me
class UnionFind {
  private:
  vector<int> p, rank;
  public:
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for(int i = 0; i < N; i++) p[i] = i;
  }
  int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
  void unionSet(int  i, int j) {
    if(!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if(rank[x] > rank[y])
        p[y] = x;
      else {
        p[x] = y;
        if(rank[x] == rank[y]) rank[y]++;
      }
    }
  } 
  int numDisjointSets() {
    int count = 0;
    for(int  i = 0; i < p.size(); i++) {
      if(p[i] == i)
        count++;
    }
    return count;
  }
  int sizeofSet(int i) {
    int parent = findSet(i);
    int count = 0;
    for(int i = 0; i < p.size(); i++) {
      if(p[i] == parent)
        count++;
    }
    return count;
  }
};

//for Segment Tree
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

int power(int x, int y, int p) 
{ 
    int res = 1; 
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
    return power(n, p-2, p)%p; 
}

void solve(){
	READ3(x, n, m);
  if(x < 10 ) {
    if(m)
      cout << "YES\n";
    else
      cout << "NO\n";
    return;
  }
	if((!m)) {
    cout << "NO\n";
    return;
  }
  while(n--) {
    if(x < 20) {
      break;
    }
    x = (x / 2) + 10;
  }
  // cout << x << "\n";
  while(m--) {
    x -= 10;
  }
  if(x <= 0) {
    cout << "YES\n";
  }
  else
    cout << "NO\n";
}

int32_t main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif


	test solve();



	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    return 0;
}