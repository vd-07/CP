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

const int mxN = 2e5 + 100;

int n, q, t[4 * mxN], lazy[4 * mxN], a[mxN];
string s, f;

void reset(int k) {
	for(int i = 0; i < 4 * k + 1; i++) {
		// marked[i] = false
		lazy[i] = -1;
	}
}

void push(int v, int l, int r, int ok) {
	if(l != r) {
		lazy[v * 2] = lazy[v * 2 + 1] = ok;
	}

	lazy[v] = -1;
}

// either make zero or one
void update(int start, int end, int curr, int l, int r, int ok) {
	if(lazy[curr] != -1) {
		t[curr] = (end - start + 1) * lazy[curr];
		push(curr, start, end, lazy[curr]);
 	}

	if(start > r || end < l) {
		return;
	}

	if(l <= start && r >= end) {
		// no of ones
		t[curr] = (end - start + 1) * ok;

		push(curr, start, end, ok);

	} else {

		int mid = (start + end) / 2;

		update(start, mid, curr * 2, l, r, ok);

		update(mid + 1, end, curr * 2 + 1, l, r, ok);

		int u = t[curr * 2], v = t[curr * 2 + 1];

		t[curr] = u + v;
	}
}

int get(int v, int start, int end, int l, int r) {
	if(lazy[v] != -1) {
		t[v] = (end - start + 1) * lazy[v];
		push(v, start, end, lazy[v]);
 	}

	if(start > r || end < l) {
		return 0;
	}

	if(l <= start && r >= end) {
		return t[v];
	}
	
	int mid = (start + end) / 2;

	int left = get(v * 2, start, mid, l, r);
	int right = get(v * 2 + 1, mid + 1, end, l, r);

	return left + right;
}

void solve() {

	cin >> n >> q;

	cin >> s >> f;

	for(int i = 0; i < n; i++) {
		update(0, n - 1, 1, i, i, f[i] - '0');
	}

	reset(n);

	// build(0, n - 1, 1);

	vector<pair<int, int>> queries(q);

	for(int i = 0; i < q; i++) {
		cin >> queries[i].first >> queries[i].second;
	}

	for(int i = q - 1; i >= 0; i--) {
		// response as count of 1s
		int l = queries[i].first - 1, r = queries[i].second - 1;

		int count1 = get(1, 0, n - 1, l, r);

		int count0 = (r - l + 1) - count1;

		debug(l, r, count1, count0);

		if(count1 == count0) {
			cout << "NO\n";
			return;
		}

		if(count1 > count0) {
			update(0, n - 1, 1, l, r, 1);
		} else {
			update(0, n - 1, 1, l, r, 0);
		}

		// for(int i = 0; i < n; i++) {
		// 	debug(get(1, 0, n - 1, i, i));
		// }
	}

	for(int i = 0; i < n; i++) {
		int ct = get(1, 0, n - 1, i, i);
		if(ct != s[i] - '0') {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
	
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