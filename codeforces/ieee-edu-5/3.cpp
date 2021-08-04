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

int n, m, p;
int a[mxN];

// // https://cp-algorithms.com/string/rabin-karp.html

// int calcHash(vector<int> const& s) {
// 	const int p = 1000000007;
// 	const int mod = 1e9 + 9;
// 	vector<long long> p_pow(s.size());
// 	p_pow[0] = 1;
// 	for (int i = 1; i < (int)p_pow.size(); i++)
// 		p_pow[i] = (p_pow[i - 1] * p) % mod;

// 	long long h_s = 0;
// 	for (int i = 0; i < (int)s.size(); i++)
// 		h_s = (h_s + (s[i]) * p_pow[i]) % mod;
// 	return h_s;
// }

// vector<int> rabin_karp(int h_s, vector<int> const& t, vector<int> const& id, int S) {
// 	int T = t.size();
// 	const int p = 1000000007;
// 	const int mod = 1e9 + 9;

// 	vector<long long> p_pow(T);
// 	p_pow[0] = 1;
// 	for (int i = 1; i < (int)p_pow.size(); i++)
// 		p_pow[i] = (p_pow[i - 1] * p) % mod;

// 	vector<long long> h(T + 1, 0);
// 	for (int i = 0; i < T; i++)
// 		h[i + 1] = (h[i] + (t[i]) * p_pow[i]) % mod;

// 	vector<int> occurences;
// 	for (int i = 0; i + S - 1 < T; i++) {
// 		long long cur_h = (h[i + S] + mod - h[i]) % mod;
// 		debug(cur_h, h_s * p_pow[i] % mod);
// 		if (cur_h == h_s * p_pow[i] % mod)
// 			occurences.push_back(id[i]);
// 	}
// 	return occurences;
// }

vector<int> calc(vector<int> &a, vector<int> &id, map<int, int> &actual) {
	// construct a window of length m
	if((int)a.size() < m) {
		return {};
	}

	vector<int> ans;

	int curr = 0, extra = 0;
	map<int, int> pseudo;

	for(int i = 0; i < m; ++ i) {
		if(actual.count(a[i])) {
			++ pseudo[a[i]];
			if(pseudo[a[i]] == actual[a[i]]) {
				++ curr;
			} else if(pseudo[a[i]] == actual[a[i]] + 1) {
				-- curr;
			}
		} else {
			++ extra;
		}
	}

	// debug(pseudo, curr, extra);

	if(extra == 0 && curr == (int)actual.size()) {
		ans.push_back(id[0]);
	}

	for(int i = m; i < (int)a.size(); ++ i) {
		// add the next one
		if(actual.count(a[i])) {
			++ pseudo[a[i]];
			if(pseudo[a[i]] == actual[a[i]]) {
				++ curr;
			} else if(pseudo[a[i]] == actual[a[i]] + 1) {
				-- curr;
			}
		} else {
			++ extra;
		}
		// remove the last one
		// i - m
		debug(i);
		if(actual.count(a[i - m])) {
			if(pseudo[a[i - m]] == actual[a[i - m]]) {
				-- curr;
			} else if(pseudo[a[i - m]] == actual[a[i - m]] + 1) {
				++ curr;
			}
			-- pseudo[a[i - m]];
		} else {
			-- extra;
		}

		// check for ans
		if(extra == 0 && curr == (int)actual.size()) {
			ans.push_back(id[i - m + 1]);
		}
		debug(pseudo, extra, curr);
	}
	return ans;
}

void solve() {
	cin >> n >> m >> p;

	vector<vector<int>> v(p), id(p);
	for (int i = 0; i < n; ++ i) {
		int a;
		cin >> a;
		v[i % p].push_back(a);
		id[i % p].push_back(i);
	}

	vector<int> b(m);
	map<int, int> actual;
	for (int i = 0; i < m; ++ i) {
		cin >> b[i];
		++ actual[b[i]];
	}

	vector<int> ans;
	for (int i = 0; i < p; ++ i) {
		for(int j: calc(v[i], id[i], actual)) {
			ans.push_back(j);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i : ans) {
		cout << i + 1 << " ";
	}
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
		solve();
	}

#ifdef CODINGINVEINS
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

	return 0;
}