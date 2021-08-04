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

int n, k;
int a[mxN];

int dp[mxN][2];

void reset() {
	for(int i = 0; i < n; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
}

int solve1(int i, bool done, int change) {
	if(i >= n) {
		return 0;
	}

	// if(dp[i][done] != -1) {
	// 	debug(i, done, dp[i][done]);
	// 	return dp[i][done];
	// }

	int value = a[0] - a[i] - change;
	int ans = abs(value) + abs(solve1(i + 1, done, change + (value)));
	if(!done) {
		ans = min(ans, abs(solve1(i + 1, true, change)));
	}

	return ans;
}

void solve() {
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int prefix[n], suffix[n];

	for(int i = 1; i < n; i++) {
		prefix[i] = abs(a[i] - a[i - 1]);
		suffix[i] = prefix[i];
		if(i > 1) {
			prefix[i] += prefix[i - 1];
		}
	}

	for(int i = n - 2; i >= 1; i--) {
		suffix[i] += suffix[i + 1];
	}

	int ans = prefix[n - 1];

	for(int i = 0; i < n; i++) {
		int value = 0;
		if(i > 1) {
			value += prefix[i - 1];
		}

		if(i + 2 < n) {
			value += suffix[i + 2];
		}

		if(i + 1 < n && i > 0) {
			value += abs(a[i + 1] - a[i - 1]);
		}

		ans = min(ans, value);
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