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

const int mxN = 5e3 + 10;

int n;
int a[mxN], b[mxN];

int rsum[mxN][mxN] = {};

int findReverse(int i, int j) {
	if(i > j) {
		return 0;
	}

	if(rsum[i][j] != -1) {
		return rsum[i][j];
	}

	if(i == j) {
		debug(i, j);
		return rsum[i][j] = a[i] * b[j];
	}

	rsum[i][j] = a[i] * b[j] + a[j] * b[i] + findReverse(i + 1, j - 1);

	findReverse(i, j - 1);
	findReverse(i + 1, j);

	return rsum[i][j];
}

void solve() {
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int pnsum[n + 1] = {};
	int snsum[n + 2] = {};
	int sum[n + 1] = {};

	for(int i = 1; i <= n; i++) {
		cin >> b[i];

		sum[i] = a[i] * b[i];

		pnsum[i] = sum[i] + pnsum[i - 1];
	}

	for(int i = n; i >= 1; i--) {
		snsum[i] = sum[i] + snsum[i + 1];
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			rsum[i][j] = -1;
		}
	}

	findReverse(1, n);

	int ans = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			ans = max(ans, rsum[i][j] + pnsum[i - 1] + snsum[j + 1]);
		}
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
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}