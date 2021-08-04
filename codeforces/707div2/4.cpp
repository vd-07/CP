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

const int mxN = 6e5 + 1;

int n, m, k;
vector<int> a, b, ftime;

int calc(int days) {
	int anger = days;

	for(int i = 1; i <= n; i++) {
		if(ftime[i] == 0) {
			continue;
		}

		// anger -= times it gets matched

		if(ftime[i] > days) {
			continue;
		}

		int leftDays = days - ftime[i];

		anger -= 1 + (leftDays) / (m * n);
	}

	return anger;
}

void solve() {
	cin >> n >> m >> k;
	a = vector<int> (n + 1), b = vector<int> (m + 1), ftime = vector<int> (max(n, m) + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for(int i = 1; i <= m; i++) {
		cin >> b[i];
	}

	if(n < m) {
		swap(n, m);
		swap(a, b);
	}

	vector<int> id(2 * n + 10);

	for(int i = 1; i <= m; i++) {
		id[b[i]] = i;
	}
	bool ok = ((n & 1) == (m & 1));

	for(int i = 1; i <= n; i++) {
		if(id[a[i]] == 0) {
			continue;
		}
		
		int gets = (i - 1) % m + 1;

		if(ok) {
			// same parity
			// move in same dirn
			if(id[a[i]] >= gets) {
				ftime[i] = id[a[i]] - gets;
			} else {
				ftime[i] = m - gets + id[a[i]];
			}
		} else {
			if(id[a[i]] >= i) {
				ftime[i] = gets + m - id[a[i]];
			} else {
				ftime[i] = gets - id[a[i]];
			}
		}
		ftime[i] = (ftime[i]) * n + i;
	}

	debug(ok, ftime);

	int l = 1, r = 1e18;

	int ans = 0;

	while(l <= r) {
		int mid = (l + r) / 2;
		int curr = calc(mid);
		if(curr == k) {
			cout << mid;
			return;
		}
		if(curr > k) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
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