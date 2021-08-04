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

const int mxN = 3e5 + 1;

int n;

vector<vector<int>> G;

vector<vector<int>> centroids;  

vector<int> siz;

vector<int> parent;

int dfs(int u, int p) {

	int sizOfSubtree = 0, currsiz = 1;

	parent[u] = p;

	for(int v : G[u]) {
			
		if(v != p) {
			dfs(v, u);
			currsiz += siz[v];
		}
			
	}

	siz[u] = currsiz;

	return currsiz;
}

void solve() {
	cin >> n;

	centroids = vector<vector<int>> (n);
	G = vector<vector<int>> (n + 1);
	siz = vector<int> (n + 1);
	parent = vector<int> (n + 1);

	int u, v;
	for(int i = 0; i < n - 1; i++) {
		cin >> u >> v;

		G[u].push_back(v);

		G[v].push_back(u);
	}

	dfs(1, -1);

	debug(siz);

	for(int i = 1; i <= n; i++) {
		int sizSub = 0;
		for(int v : G[i]) {
			if(v == parent[i]) {
				sizSub = max(sizSub, n - siz[i]);
			} else {
				sizSub = max(sizSub, siz[v]);
			}
		}
		// debug(i, G[i], sizSub);
		centroids[sizSub].push_back(i);
	}

	vector<int> toCut;

	debug(centroids);

	for(int i = 0; i < n; i++) {
		if(!centroids[i].empty()) {
			debug(i, centroids[i].size());
			toCut = centroids[i];
			break;
		}
	}

	debug(toCut);

	// symmetric
	assert(toCut.size() <= 2);

	if(toCut.size() < 2) {
		cout << 1 << " " << G[1][0] << "\n";
		cout << 1 << " " << G[1][0] << "\n";
	} else {
		int u = toCut[0], v = toCut[1];

		int x = -1;

		if(G[u].size() > 1) {
			if(G[u][0] != v) {
				x = G[u][0];
			} else {
				x = G[u][1];
			}
			cout << u << " " << x << "\n";
			cout << x << " " << v << "\n";
		} else {
			if(G[v][0] != u) {
				x = G[v][0];
			} else {
				x = G[v][1];
			}
			cout << v << " " << x << "\n";
			cout << x << " " << u << "\n";
		}
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
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}