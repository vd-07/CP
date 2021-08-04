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

#define int long long int

const int mxn = 1e5 + 1;

int n;

int a[mxn];

int construct(vector<int> seg1) {
	int curr = 0;

	int prev = -1;

	int ans = 0;

	for(int i = 1; i <= n; i++) {
		if(seg1[curr] == i) {
			curr++;
			continue;
		} else {
			if(prev == a[i]) {
				continue;
			} else {
				ans++;
				prev = a[i];
			}
		}
	}

	return ans;
}

void solve() {
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int dp[n + 1] = {};

	dp[1] = 1;

	int prevDiff = 1;

	vector<int> track(n + 1);

	track[1] = 1;

	for(int i = 2; i <= n; i++) {

		track[i] = prevDiff;

		if(a[i] != a[i - 1]) {
			prevDiff = i - 1;
		}

		if(a[i] == a[prevDiff]) {
			// same adjacents
			dp[i] = dp[i - 1];
		} else {
			if(a[i] == a[i - 1]) {
				dp[i] = dp[i - 1];
			} else {
				prevDiff = i - 1;
				dp[i] = dp[i - 1] + 1;
			}

			track[i] = prevDiff;

			dp[i] = max(dp[i], dp[prevDiff] + 1);
		}
	}

	vector<int> seg1, seg2;

	// construct the answer
	// is it guaranteed that i will always select first and last in the same segment
	// nopes : 1 2 1
	// i guess the answer is yes

	seg1.push_back(n);

	for(int i = n; i >= 1; ) {
		int prevDiff = track[i];

		debug(prevDiff);

		if(dp[i] == dp[prevDiff] + 1) {
			seg1.push_back(prevDiff);
			i = prevDiff;
		} else {
			i--;
		}
	}

	reverse(seg1.begin(), seg1.end());

	int ans = construct(seg1);

	debug(seg1);

	cout << dp[n] + ans;
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