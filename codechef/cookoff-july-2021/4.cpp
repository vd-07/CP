//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

// #define int long long
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

const int mxN = 1e3 + 1;

int n, k;
int a[mxN];

// int recur(int i, int k) {
// 	if(i == n || k == 0) {
// 		return 0;
// 	}

// 	if(dp[i][k] != -1) {
// 		return dp[i][k];
// 	}

// 	int count = 0;
// 	int ans = 0;

// 	for(int j = i; j < n; ++ j) {
// 		if(a[j] == a[i]) {
// 			++ count;
// 		} else {
// 			ans = max(ans, count + recur(j, k - 1));
// 		}
// 	}

// 	return dp[i][k] = max(ans, count);
// }

void solve() {
	cin >> n >> k;

	// vector<vector<int>> freq(n, vector<int> (mxN));
	vector<int> last(n, -1);
	vector<int> id(mxN, -1);

	for(int i = 0; i < n; ++ i) {
		cin >> a[i];
		// ++ freq[i][a[i]];
		last[i] = id[a[i]];
		id[a[i]] = i;
	}

	// vector<vector<int>> pref = freq;

	// for(int i = 1; i < n; ++ i) {
	// 	for(int j = 0; j < mxN; ++ j) {
	// 		pref[i][j] += pref[i - 1][j];
	// 	}
	// }

	// for(int i = n - 2; i >= 0; -- i) {
	// 	for(int j = 0; j < mxN; ++ j) {
	// 		freq[i][j] += freq[i + 1][j];
	// 	}
	// }

	vector<vector<int>> dp(k + 1, vector<int> (n, 1));
	vector<int> pref_max(k + 1);

	int ans = 0;
	
	for(int j = 0; j < n; ++ j) {
		for(int i = k; i >= 0; -- i) {
			if(i > 0) {
				dp[i][j] = pref_max[i - 1] + 1;
			}

			if(last[j] != -1) {
				dp[i][j] = max(dp[i][j], dp[i][last[j]] + 1);
			}

			pref_max[i] = max(pref_max[i], dp[i][j]);
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << "\n";
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
	cin >> t;
	while(t--) {
		solve();
	}

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}