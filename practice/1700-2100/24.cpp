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

int n, k, q;
string s;
vector<int> dp;

void build(int i) {
	if(i > n) {
		return;
	}

	int l = 2 * i + 1, r = 2 * i;
	build(l), build(r);

	if(s[i - 1] == '0') {
		dp[i] = (l <= n ? dp[l] : 1);
	} else if(s[i - 1] == '1') {
		dp[i] = (r <= n ? dp[r] : 1);
	} else {
		dp[i] = (r <= n ? dp[l] + dp[r] : 2);
	}
}

string constructPath(int p) {
	string ans = "";
	while(p > 1) {
		ans += char((p % 2) + '0');
		p /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

void update(int i, string &path, char &c, int j = 0) {
	if(i > n) {
		return;
	}

	int l = 2 * i + 1, r = 2 * i;
	debug(i, j);

	if(j == (int)path.size()) {
		// update
		s[i - 1] = c;
	} else {
		if(path[j] == '1') {
			// left
			update(l, path, c, j + 1);
		} else {
			update(r, path, c, j + 1);
		}	
	}

	if(s[i - 1] == '0') {
		dp[i] = (l <= n ? dp[l] : 1);
	} else if(s[i - 1] == '1') {
		dp[i] = (r <= n ? dp[r] : 1);
	} else {
		dp[i] = (r <= n ? dp[l] + dp[r] : 2);
	}
}

void queries() {
	cin >> q;
	debug(s);
	while(q --) {
		int p;
		char c;
		cin >> p >> c;
		p = n - p + 1;

		string path = constructPath(p);

		update(1, path, c);

		debug(p, s, path);

		cout << dp[1] << "\n";
	}
}

void solve() {
	cin >> k;
	n = (1 << k) - 1;

	cin >> s;
	reverse(s.begin(), s.end());

	dp = vector<int> (n + 1);
	build(1);

	queries();
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
	while(t--) {
		solve();
	}

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}	