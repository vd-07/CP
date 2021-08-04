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

const int mxN = (1 << 17) + 1;

int n, m, t[4 * mxN], a[mxN];

void build(int start, int end, int curr, int level) {
	if(start == end) {
		t[curr] = a[start];
		return;
	} 

	int mid = (start + end) / 2;

	build(start, mid, curr * 2, level - 1);
	build(mid + 1, end, curr * 2 + 1, level - 1);

	int u = t[curr * 2], v = t[curr * 2 + 1];

	if(level & 1) {
		t[curr] = u | v;
	} else {
		t[curr] = u ^ v;
	}
}

void update(int start, int end, int curr, int level, int &index, int &value) {
	if(start == end) {
		// debug(start);
		assert(start == index);
		t[curr] = value;
		return;
	}

	int mid = (start + end) / 2;

	if(index <= mid) {
		update(start, mid, curr * 2, level - 1, index, value);
	} else {
		update(mid + 1, end, curr * 2 + 1, level - 1, index, value);
	}

	int u = t[curr * 2], v = t[curr * 2 + 1];

	if(level & 1) {
		t[curr] = u | v;
	} else {
		t[curr] = u ^ v;
	}
}

void solve() {
	cin >> n >> m;

	for(int i = 1; i <= (1 << n); i++) {
		cin >> a[i];
	}

	// start, end, curr, level
	build(1, 1 << n, 1, n);

	while(m --) {
		int p, b;
		cin >> p >> b;

		update(1, 1 << n, 1, n, p, b);

		cout << t[1] << "\n";
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