//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

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

const int mxn = 2e5 + 100;

int n;
vector<vector<int>> adj;
vector<int> visited;
vector<bool> marked;
vector<int> p;
vector<int> cycles;

void dfsc(int u, int g) {
	if(visited[u] == 1) {
		// cycle detected
		int node = g;
		marked[u] = true;

		cycles.push_back(u);

		while(node != u) {
			cycles.push_back(node);
			marked[node] = true;
			node = p[node];
		}

		return;
	}

	visited[u] = 1;

	p[u] = g;

	for(int v : adj[u]) {
		if(v != g) {
			dfsc(v, u);
		}
	}

	visited[u] = 2;
}

int dfs(int u) {

	int curr = 1;

	visited[u] = 1;

	for(int v : adj[u]) {
		if(!visited[v] && !marked[v]) {
			curr += dfs(v);
		}
	}

	return curr;
}

void solve() {

	cin >> n;

	adj = vector<vector<int>> (n + 1);
	visited = vector<int> (n + 1);
	marked = vector<bool> (n + 1);
	p = vector<int> (n + 1);
	cycles.clear();

	for(int i = 1; i <= n; i++) {
		int u, v;

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// detect cycle

	dfsc(1, 1);

	debug(marked);

	int ans = 0;

	visited = vector<int> (n + 1);

	for(int i : cycles) {
		if(visited[i]) {
			continue;
		}

		int nv = dfs(i);

		debug(nv);

		ans += (nv * (nv - 1)) / 2;
		ans += nv * (n - nv);
	}
	
	cout << ans << "\n";
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
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}