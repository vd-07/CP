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
int a[mxN], pmin[mxN], pmax[mxN], smin[mxN], smax[mxN], psum[mxN];

void build() {
	// pmin[1] = pmax[1] = psum[1] = a[1];

	for(int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + a[i];
		pmin[i] = min(pmin[i - 1], psum[i]);
		pmax[i] = max(pmax[i - 1], psum[i]);
	}

	// smin[n] = smax[n] = a[n];

	// for(int i = n - 1; i >= 1; i--) {
	// 	a[i] += a[i + 1];
	// 	smin[i] = min(smin[i + 1], a[i]);
	// 	smax[i] = max(smax[i + 1], a[i]);
	// }
}

void ansQuery(int l, int r) {
	int l1 = pmin[l - 1], r1 = pmax[l - 1];
	int l2 = l1, r2 = r1;
	debug(l1, r1);
	if(r < n) {
		l2 = smin[r + 1], r2 = smax[r + 1];
		debug(l2, r2);
		l2 += psum[l - 1], r2 += psum[l - 1];
	}

	l = min(l1, l2), r = max(r1, r2);

	cout << r - l + 1;

	cout << "\n";
}

void query() {
	while(m--) {
		int l, r;
		cin >> l >> r;
		ansQuery(l ,r);
	}
}

void solve() {
	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		char c;
		cin >> c;

		if(c == '+') {
			a[i] = 1;
		} else {
			a[i] = -1;
		}
	}

	build();
	query();
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