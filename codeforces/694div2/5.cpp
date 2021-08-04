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

	// #define int long long
const int N = 1e6 + 1;

int n, q;
int spf[N];

void sieve() {
	for(int i = 1; i < N; i++) {
		spf[i] = i;
	}

	for(int i = 2; i * i < N; i++) {
		if(spf[i] == i) {
			for(int j = i * i; j < N; j += i) {
				spf[j] = i;
			}
		}
	}
}

void solve() {
	cin >> n;
	int a[n];
	map<int, int> m1;

	for(int i = 0; i < n; i++) {
		cin >> a[i];

		int product = 1;

		while(a[i] > 1) {
			int factor = spf[a[i]];
			int exponent = 0;
			while(a[i] % factor == 0) {
				a[i] /= factor;
				exponent++;
			}
			if(exponent & 1) {
				product *= factor;
			}
		}

		m1[product] ++;
	}

	int a1 = 0, ct = 0, a2 = 0;

	for(pair<int, int> p : m1) {
		a1 = max(a1, p.second);

		// as 1 is also pfs
		if(p.first != 1 && (p.second & 1)) {
			a2 = max(a2, p.second);
		} else {
			ct += p.second;
		}
	}

	a2 = max(a2, ct);

	debug(a1, a2);

	cin >> q;
	while(q--) {
		long long int w;
		cin >> w;
		if(w < 1) {
			cout << a1 << "\n";
		} else {
			cout << a2 << "\n";
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

	sieve();

	// test cases
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}