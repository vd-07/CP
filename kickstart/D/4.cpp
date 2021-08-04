//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 10;

int n, p, q, S, L, R;
int a[N];

int power(int base, int expo) {
	if(expo < 1) {
		return 1;
	}

	return base * power(base, expo - 1);
}

int calc(int value) {
	int count = 0;

	if(value == 0) {
		return 0;
	}

	// cerr << value;

	while(value % p == 0) {
		value /= p;
		count++;
	}

	return count;
}

struct SegmentTreeNode {
	int ans;
	int less;
void assignLeaf(int value) {
    ans = calc(value / p);
    less = (value < p);
  }
void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
	ans = left.ans + right.ans;
	less = left.less + right.less;
	// sumAll = left.sumAll + right.sumAll;
  }
int getValue() {
	// int ans1 = (R - L + 1) * (calc(S) + 1) + (S - 1) * sumAll + sumK;
	// int ans2 = S * (sumK) + R - L + 1;
	cerr << less;
	 return (ans + (R - L + 1 - less));
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
	cin >> n >> q >> p;

	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
	}

	SegmentTree<int, int> st(a, n);

	while(q --) {
		int type;

		cin >> type;

		switch(type) {
			case 1:
				int pos, val;
				cin >> pos >> val;

				st.update(pos - 1, val);
			break;

			case 2:

				cin >> S >> L >> R;

				int ans = st.getValue(L - 1, R - 1);

				// ans = (ans + R - L + 1) * S;

				cout << ans << " ";
		}

	}

	cout << "\n";
}

int32_t main() {
	#ifdef CODINGINVEINS
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
	cin >> t;
	for(int i = 1; i <= t; i++) {
        cout << "Case #"<< i << ": ";
        solve();
    	}
	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif

	return 0;
}