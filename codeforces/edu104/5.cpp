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

	// #define int long long

const int mxN = 3e5 + 1;

int n1, n2, n3, n4;
int m1, m2, m3;

// {cost, node}
vector<pair<int, int>> a, b, c, d;

void inputCost() {
	
	a = vector<pair<int, int>> (n1);
	b = vector<pair<int, int>> (n2);
	c = vector<pair<int, int>> (n3);
	d = vector<pair<int, int>> (n4);

	for(int i = 0; i < n1; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}

	for(int i = 0; i < n2; i++) {
		cin >> b[i].first;
		b[i].second = i + 1;
	}

	for(int i = 0; i < n3; i++) {
		cin >> c[i].first;
		c[i].second = i + 1;
	}

	for(int i = 0; i < n4; i++) {
		cin >> d[i].first;
		d[i].second = i + 1;
	}

}

set<int> G1[mxN], G2[mxN], G3[mxN];

void solve() {
	cin >> n1 >> n2 >> n3 >> n4;

	inputCost();
	// debug(n1, n2, n3, n4);
	// debug(a, b, c, d);

	cin >> m1;

	int u, v;
	for(int i = 0; i < m1; i++) {
		cin >> u >> v;
		G1[u].insert(v);
	}

	cin >> m2;
	for(int i = 0; i < m2; i++) {
		cin >> u >> v;
		G2[u].insert(v);
	}

	cin >> m3;
	for(int i = 0; i < m3; i++) {
		cin >> u >> v;
		debug(u, v);
		G3[u].insert(v);
	}

	sort(d.begin(), d.end());

	// sorted according to cost

	for(pair<int, int> &p : c) {
		int u = p.second;
		int currCost = p.first;

		bool ok = false;

		for(pair<int, int> q : d) {
			int v = q.second;
			if(G3[u].find(v) == G3[u].end()) {
				debug(v, u);
				currCost += q.first;
				ok = true;
				break;
			}
		}

		if(ok) {
			p.first = currCost;
		} else {
			p.first = 1e9;
		}
	}

	debug(c);

	sort(c.begin(), c.end());

	// sorted according to cost

	for(pair<int, int> &p : b) {
		int u = p.second;
		int currCost = p.first;

		bool ok = false;

		for(pair<int, int> q : c) {
			int v = q.second;
			if(G2[u].find(v) == G2[u].end()) {
				currCost += q.first;
				ok = true;
				break;
			}
		}

		if(ok) {
			p.first = currCost;
		} else {
			p.first = 1e9;
		}
	}

	sort(b.begin(), b.end());

	// sorted according to cost

	for(pair<int, int> &p : a) {
		int u = p.second;
		int currCost = p.first;

		bool ok = false;

		for(pair<int, int> q : b) {
			int v = q.second;
			if(G1[u].find(v) == G1[u].end()) {
				currCost += q.first;
				ok = true;
				break;
			}
		}

		if(ok) {
			p.first = currCost;
		} else {
			p.first = 1e9;
		}
	}

	int ans = 1e9;

	for(pair<int, int> p : a) {
		ans = min(ans, p.first);
	}

	if(ans >= 1e9) {
		ans = -1;
	}
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

	
	solve();
	

	return 0;
}