//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

/*

"Everyone had to be drunk on something to keep moving on. 
Everyone… was a slave to something. Even him."

*/

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

const int mod = 998244353;

int n, k;
int a[mxN], fact[mxN], invFact[mxN];

int binPower(int base, int exponent) {
	int result = 1;

	while(exponent) {
		if(exponent & 1) {
			result = (result * base) % mod;
		}

		base = (base * base) % mod;

		exponent /= 2;
	}

	return result;
}

int modInverse(int num) {
	return binPower(num, mod - 2);
}

void process() {
	fact[0] = 1;

	for(int i = 1; i < mxN; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}

	invFact[mxN - 1] = modInverse(fact[mxN - 1]);;

	for(int i = mxN - 2; i >= 0; i--) {
		invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
	}

	for(int i = 0; i < mxN; i++) {
		invFact[i] = (invFact[i] * invFact[i]) % mod;
	}
}

void solve() {
	cin >> n;

	for(int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}

	sort(a, a + (2 * n));

	int ans = 0;

	for(int i = 0; i < n; i++) {
		ans -= a[i];
	}

	for(int i = n; i < 2 * n; i++) {
		ans += a[i];
	}

	ans %= mod;

	ans = (ans * fact[2 * n]) % mod;

	ans = (ans * invFact[n]) % mod;

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

	process();

	while(t--) {
		solve();
	}

	return 0;
}