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

int n1, n2, n3;

int m1 = 1e10, m2 = 1e10, m3 = 1e10;
int s1 = 0, s2 = 0, s3 = 0;

void take_ip() {
	int t;

	for(int i = 0; i < n1; i++) {
		cin >> t;
		s1 += t;
		m1 = min(m1, t);
	}

	if(n1 != 1)
	s1 -= m1;

	for(int i = 0; i < n2; i++) {
		cin >> t;
		s2 += t;
		m2 = min(m2, t);
	}

	if(n2 != 1)
	s2 -= m2;

	for(int i = 0; i < n3; i++) {
		cin >> t;
		s3 += t;
		m3 = min(m3, t);
	}

	if(n3 != 1)
	s3 -= m3;
}

void solve() {
	cin >> n1 >> n2 >> n3;

	take_ip();

	int ans = 0;

	if(n1 == 1) {
		m1 = 0;
	}

	if(n2 == 1) {
		m2 = 0;
	}

	if(n3 == 1) {
		m3 = 0;
	}

	int sum = m1 + s1 + m2 + s2 + m3 + s3;

	vector<int> v = {m1, m2, m3, s1, s2, s3};

	debug(v, sum);

	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++) {
			if(i != j) {
				if(v[i] == 0) {
					ans = max(ans, sum - 2 * (v[i + 3]));
				} else if(v[j] == 0) {
					ans = max(ans, sum - 2 * (v[j + 3]));
				} else {
					ans = max(ans, sum - 2 * (v[i] + v[j]));	
				}
			}
		}
	}

	cout << ans;
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