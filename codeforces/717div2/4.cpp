//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e5 + 1;
int spf[N];

int n, q;
int a[N];

void sieve() {
	for(int i = 1; i < N; i++) {
		spf[i] = i;
	}

	for(int i = 2; i * i <= N; i++) {
		if(spf[i] == i) {
			for(int j = i * i; j < N; j += i) {
				spf[j] = i;
			}
		}
	}
}

struct SegmentTreeNode {
int answer;
set<int> s;
void assignLeaf(int value) {
    answer = 1;
    while(value > 1) {
    	int curr = spf[value];
    	while(value % curr == 0) {
    		value /= curr;
    	}
    	s.insert(curr);
    }
  }
void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
	answer = left.answer + right.answer;
	bool ok = true;
    for(int i : left.s) {
    	if(right.s.find(i) != right.s.end()) {
    		ok = false;
    		break;
    	}
    }
    answer -= ok;
    for(int i : right.s) {
    	s.insert(i);
    }
    for(int i : left.s) {
    	s.insert(i);
    }
  }
int getValue() {
    return answer;
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

void solve() {
	cin >> n >> q;

	sieve();

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	SegmentTree<int, int> st(a, n);

	while(q--) {
		int l, r;
		cin >> l >> r;
		int answer = st.getValue(l - 1, r - 1);
		cout << answer << "\n";
	}

}

int32_t main() {
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	// for fast i/o
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	// test cases
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}