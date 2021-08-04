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

const int mxN = 2e6 + 1;

// int n, m;
// int r[mxN], c[mxN];

// int x[mxN], y[mxN];

// int calc(int up) {
// 	if(up < 0) {
// 		return INT_MAX;
// 	}
// 	int moves = 0;

// 	for(int i = 1; i <= n; i++) {
// 		int nx = min(x[i] + up, 1000010LL);
// 		int moveright = c[nx] - y[i] + 1;
// 		int moveup = r[y[i]] - nx + 1;

// 		if(moveup <= 0) {
// 			continue;
// 		}

// 		if(moveright <= 0) {
// 			return INT_MAX;
// 		}

// 		debug(up, moveright, nx, c[nx]);

// 		moves = max(moves, moveright);
// 	}

// 	return moves + up;
// }

// int linearSearch(int lo, int hi) {
// 	int ans = 1e6;

// 	while(lo < hi) {
// 		int mid = lo + hi >> 1;

// 		int moves1 = calc(mid);
// 		int moves2 = calc(mid + 1);
// 		int moves3 = calc(mid - 1);

// 		int curr = min({moves1, moves2, moves3});

// 		ans = min(ans, curr);

// 		if(curr == moves3 || curr == moves1) {
// 			hi = mid - 1;
// 		}
// 		else {
// 			lo = mid + 1;
// 		}
// 	}

// 	return ans;
// }

// void solve() {
// 	cin >> n >> m;
// 	for(int i = 1; i <= n; i++) {
// 		cin >> x[i] >> y[i];
// 	}

// 	int sx, sy;
// 	for(int i = 1; i <= m; i++) {
// 		cin >> sx >> sy;
		
// 		// 
// 		r[sy] = max(r[sy], sx);
// 		c[sx] = max(c[sx], sy);
// 	}

// 	for(int i = mxN - 2; i >= 0; i--) {
// 		r[i] = max(r[i], r[i + 1]);
// 		c[i] = max(c[i], c[i + 1]);
// 	}

// 	// int u = 0, v = 0;
// 	// int ud = 0, vd = 0;

// 	// for(int i = 1; i <= n; i++) {
// 	// 	int moveright = c[x[i]] - x[i] + 1;
// 	// 	int moveup = r[y[i]] - y[i] + 1;
		
// 	// 	if(moveright <= 0 || moveup <= 0) {
// 	// 		continue;
// 	// 	}

// 	// 	debug(i, moveright, moveup);

// 	// 	if(moveright < moveup) {
// 	// 		v = max(moveright, v);
// 	// 	}
// 	// 	else {
// 	// 		u = max(moveup, u);
// 	// 	}
// 	// }

// 	int ans = linearSearch(0, 1e6);
// 	cout << ans;
// }

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

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> robbers(n), searchLights(m);
	
	for(pair<int, int> &p : robbers) {
		cin >> p.first >> p.second;
	}

	for(pair<int, int> &p : searchLights) {
		cin >> p.first >> p.second;
	}

	vector<pair<int, int>> moves;

	for(pair<int, int> p : robbers) {

		int x = p.first, y = p.second;
		for(pair<int, int> q : searchLights) {

			int a = q.first, b = q.second;

			if(a >= x && b >= y) {
				moves.push_back({a - x, b - y});
			}


		}
	}

	sort(moves.rbegin(), moves.rend());

	int ans = INT_MAX, big = -1;

	for(pair<int, int> p : moves) {
		ans = min(ans, p.first + 1 + big + 1);
		big = max(big, p.second);
	}

	ans = min(ans, big + 1);

	cout << ans;

	return 0;
}