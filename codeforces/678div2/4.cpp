//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

/*

"Everyone had to be drunk on something to keep moving on. 
Everyone… was a slave to something. Even Him."

*/

// debug start
	template <typename A, typename B>
	string to_string(pair<A, B> p);
	 
	template <typename A, typename B, typename C>
	string to_string(tuple<A, B, C> p);
	 
	template <typename A, typename B, typename C, typename D>
	string to_string(tuple<A, B, C, D> p);
	 
	string to_string(const string& s) {
	  return '"' + s + '"';
	}
	 
	string to_string(const char* s) {
	  return to_string((string) s);
	}
	 
	string to_string(bool b) {
	  return (b ? "true" : "false");
	}
	 
	string to_string(vector<bool> v) {
	  bool first = true;
	  string res = "{";
	  for (int i = 0; i < static_cast<int>(v.size()); i++) {
	    if (!first) {
	      res += ", ";
	    }
	    first = false;
	    res += to_string(v[i]);
	  }
	  res += "}";
	  return res;
	}
	 
	template <size_t N>
	string to_string(bitset<N> v) {
	  string res = "";
	  for (size_t i = 0; i < N; i++) {
	    res += static_cast<char>('0' + v[i]);
	  }
	  return res;
	}
	 
	template <typename A>
	string to_string(A v) {
	  bool first = true;
	  string res = "{";
	  for (const auto &x : v) {
	    if (!first) {
	      res += ", ";
	    }
	    first = false;
	    res += to_string(x);
	  }
	  res += "}";
	  return res;
	}
	 
	template <typename A, typename B>
	string to_string(pair<A, B> p) {
	  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
	}
	 
	template <typename A, typename B, typename C>
	string to_string(tuple<A, B, C> p) {
	  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
	}
	 
	template <typename A, typename B, typename C, typename D>
	string to_string(tuple<A, B, C, D> p) {
	  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
	}
	 
	void debug_out() { cerr << endl; }
	 
	template <typename Head, typename... Tail>
	void debug_out(Head H, Tail... T) {
	  cerr << " " << to_string(H);
	  debug_out(T...);
	}
	 
	#ifndef ONLINE_JUDGE
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
	#else
	#define debug(...) 42
	#endif
// end debug

	#define int long long

const int mxN = 3e5 + 1;


struct Tree {
	int maxValue;
	int deficiet;
	int leafNode;	
};


int n;
int a[mxN];
vector<int> G[mxN];
Tree node[mxN];



void dfs(int u, int parent) {

	// go to all neighbours
	int currMax = 0, currDeficiet = 0, currLeaf = 0;
	for(int v : G[u]) {
		if(v != parent) {
			dfs(v, u);
			currMax = max(currMax, node[v].maxValue);
			// currDeficiet += node[v].deficiet;
			currLeaf += node[v].leafNode;
		}
	}	

	for(int v : G[u]) {
		// what if there are multiple currMax
		currDeficiet += node[v].deficiet + (node[v].leafNode) * (currMax - node[v].maxValue);
	}

	// # fix and then return

	// time to distribute 
	if(currLeaf == 0) {
		node[u].leafNode = 1;
		node[u].maxValue = a[u];
		node[u].deficiet = 0;
		return;
	}

	int y = a[u];

	if(currDeficiet >= y) {
		currDeficiet -= y;
		node[u].leafNode = currLeaf;
		node[u].maxValue = currMax;
		node[u].deficiet = currDeficiet;
		return;
	}

	y -= currDeficiet;
	currDeficiet = 0;

	currMax += y / currLeaf;

	if(y % currLeaf != 0) {
		currMax ++;
		currDeficiet = (currLeaf - (y % currLeaf));
	}

	node[u].leafNode = currLeaf;
	node[u].maxValue = currMax;
	node[u].deficiet = currDeficiet;
}

void solve() {
	cin >> n;

	int u, v;
	for(int i = 2; i <= n; i++) {
		v = i;
		cin >> u;

		G[u].push_back(v);
	}

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dfs(1, 1);

	int ans = node[1].maxValue;

	cout << ans;

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
	while(t--) {
		solve();
	}

	return 0;
}