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

int n, q;
int a[mxN];
int spf[mxN];

void sieve() {
	for(int i = 1; i < mxN; i++) {
		spf[i] = i;
	}

	for(int i = 2; i * i < mxN; i++) {
		if(spf[i] == i) {
			for(int j = i * i; j < mxN; j += i) {
				spf[j] = i;
			}
		}
	}
}

void solve() {
	cin >> n >> q;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int LOG = log2(n) + 1;

	vector<vector<int>> dp(n + 2, vector<int> (LOG + 1, n + 1));

	vector<int> go(n + 1, n + 1);

	vector<int> occurance(mxN, n + 1);

	sieve();

	for(int i = n; i >= 1; i--) {
		while(a[i] > 1) {
			int currPrime = spf[a[i]];

			while(a[i] % currPrime == 0) {
				a[i] /= currPrime;
			}

			go[i] = min(go[i], occurance[currPrime]);

			occurance[currPrime] = i;
		}

		if(i < n) {
			go[i] = min(go[i], go[i + 1]);
		}

		dp[i][0] = go[i];
	}

	debug(go);

	for(int i = 1; i <= LOG; i++) {
		for(int id = 1; id <= n; id++) {
			dp[id][i] = dp[dp[id][i - 1]][i - 1];	
		}
	}

	while(q--) {

		int l, r;

		cin >> l >> r;

		int ans = 0;

		for(int i = LOG; i >= 0; i--) {
			// if(l == r) {
			// 	break;
			// }
			if(dp[l][i] <= r) {
				debug(l, i);
				l = dp[l][i];
				debug(l, i);
				ans += (1 << i);
			}
		}

		// if(l != r) {
		// 	++ ans;
		// }

		cout << ans + 1 << "\n";

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