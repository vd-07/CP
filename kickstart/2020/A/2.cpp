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
ll A[1000][2000];
void solve(){
READ(n); READ2(k,p);
ll ans = 0 , temp;
vector<vector<ll> > plates(n+1);
f(i,0,n) {
    f(j,0,k) {
        cin>>temp;
        plates[i+1].push_back(temp);
    }
}
f(i,0,n+1)
    f(j,0,p+1)
        A[i][j]=0;
for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= p; j++) {
        // vector<queue<ll> > tempn;
        // ll  ind = -1;
        // vector<queue<ll> > temp(plates);
        ll maxi = 0;
        // for(int k=0;k<=p;k++)
        //     A[i][0]=max(A[i][0],A[i-1][k]);
        // vector<queue<ll> > hero(plates);
        // if(j==0) {
        //     A[i][j]=A[i-1][j];
        //     continue;
        // }
        for(int k = 0; k <= j; k++)
        {
            if(k >= 1 && k <= plates[i].size())
            maxi += plates[i][k-1];
            if (A[i][j] < A[i-1][j-k] + maxi) 
            A[i][j] = A[i-1][j-k] + maxi;
            // ind = k;
            
        
        }
        // if (A[i][j] < A[i-1][j-k] + maxi) 
        //     A[i][j] = A[i-1][j-k] + maxi;    
        // plates = tempn;
        // while(ind > 0) {
        //     if(plates[i].empty())
        //     break;
        //     plates[i].pop();
        //     ind--;
        // }
    }    
}
// f(i,1,n+1) {
//     f(j,0,p+1)
//     cout<<i<<"the stack : "<<j<<"th plate : "<<A[i][j]<<" ";
//     cout<<endl;
// }
cout<<A[n][p]<<'\n';
}

int main(){
	ll t;
	cin>>t;
	for(int i=1;i<=t;i++) {
	    cout<<"Case #"<<i<<": ";
	    solve();
	}
    return 0;
}