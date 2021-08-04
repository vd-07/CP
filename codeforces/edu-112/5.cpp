//Author : Vivek Dubey
#include "bits/stdc++.h"
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
	 
	#ifdef CODINGINVEINS
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
	#else
	#define debug(...) 42
	#endif
// end 

#define int long long

const int mxN = 3e5 + 1;

int n, k;
int a[mxN];

long recur(int i, int prev, vector<array<long, 3>> &weight, vector<vector<int>> &dp) {
	if (i >= (int)weight.size()) {
		return 0;
	}

	if (dp[i][prev] != -1) {
		return dp[i][prev];
	}

	long ans = 0;
	if (weight[i][0] >= weight[prev][1]) {
		ans = weight[i][2] + recur(i + 1, i, weight, dp);
	} 

	ans = max(ans, recur(i + 1, prev, weight, dp));

	debug(ans, i, prev);

	return dp[i][prev] = ans;
}

long solve(vector<long> pickup, vector<long> drop, vector<long> tip) {
	int n = pickup.size();
	vector<array<long, 3>> weight;
	weight.push_back({0, 0, 0});

	for (int i = 0; i < n; ++ i) {
		weight.push_back({pickup[i], drop[i], drop[i] - pickup[i] + tip[i]});
	}
	sort(weight.begin(), weight.end());

	vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

	long ans = recur(1, 0, weight, dp);
	debug(weight);
	return ans;
}

int32_t main() {
#ifdef CODINGINVEINS
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
	while (t--) {
		int n;
		cin >> n;
		vector<long> p(n), d(n), tip(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> d[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> tip[i];
		}
		cout << solve(p, d, tip);
	}

#ifdef CODINGINVEINS
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

	return 0;
}