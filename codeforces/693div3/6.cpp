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

int n, m;

vector<vector<int>> G2;
vector<int> dist, ans;
vector<int> vis;

void bfs(){
                                               
	dist[1] = 0;

	queue<int> q;
	q.push(1);

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(int v : G2[u]) {
			if(dist[v] == 1e9) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	debug(dist);
}

// int dfs(int u) {
// 	if(dist[u] < 1e9) {
// 		return dist[u];
// 	}

// 	if(visited[u]) {
// 		// cycle

// 		return 1e9;
// 	}

// 	if(u == 1) {
// 		return 0;
// 	}

// 	visited[u] ++;

// 	int curr = 1e9;

// 	for(int v : G2[u]) {
// 		curr = min(dfs(v), curr);
// 	}

// 	return dist[u] = curr + 1;
// }

void dfs(int u) {

	ans[u] = dist[u];

	for(int v : G2[u]) {

		// since they are connected
		// either one level up or down or same
		// only one up is allowed
		// also need another dp vector
		// since i dont know if level has been crossed or not

		if(ans[v] == 1e9 && dist[u] < dist[v]) {
			// level down so allowed
			dfs(v);
		}

		if(dist[v] > dist[u]) {
			// can take the level up
			ans[u] = min(ans[u], ans[v]);
		} else {
			// already one level up
			ans[u] = min(ans[u], dist[v]);
		}
	}

}

void reset() {
	vis = vector<int> (n + 1);
	G2 = vector<vector<int>> (n + 1);

	dist = vector<int> (n + 1, 1e9);
	ans = vector<int> (n + 1, 1e9);
}

void solve() {
	cin >> n >> m;

	int u, v;

	reset();

	for(int i = 0; i < m; i++) {
		cin >> u >> v;

		G2[u].push_back(v);

		// G1[u].push_back(v);
		// G1[v].push_back(u);
	}

	bfs();

	dfs(1);

	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}

	cout << "\n";

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