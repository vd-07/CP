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

	const int mod = 1e9 + 7;

const int mxN = 2e5 + 1;

int power(int base, int ep) {
	int res = 1;
	while(ep) {
		if(ep & 1) {
			res *= base;
			res %= mod;
		}

		base *= base;
		base %= mod;

		ep >>= 1;
	}
	return res;
}

int modInverse(int n) {
	return power(n, mod - 2) % mod;
}

string s;
int p2[mxN], p11[mxN];

int val[mxN];

int convert() {
	int ans = 0;
	for(char c : s) {
		ans = ans * 10 + (int)(c - '0');
		ans %= mod;
	}
	return ans;
}

void solve() {
	cin >> s;
	
	int ans = 0;
		
	int n = s.size();

	int p10 = 1;

	for(int i = n - 1; i >= 0; i--) {
		int r = n - i - 1;

		int x = s[i] - '0';

		int temp = val[r];

		temp += ((i * (i + 1)) / 2) * p10;
		temp %= mod;

		temp *= x;

		debug(temp);

		temp %= mod;

		// int temp = x * (p11[r] - 1 + mod);
		// temp %= mod;

		// int temp1 = (p2[i] - 1 + mod) * x;
		// temp1 %= mod;

		// temp1 *= p10;
		// temp1 %= mod;

		ans += temp;
		ans %= mod;

		p10 *= 10;
		p10 %= mod;


	}

	// ans -= convert();
	// ans += mod;

	ans %= mod;


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

	// p2[0] = 1, p11[0] = 1;

	val[0] = 0;

	int p10 = 1;
	for(int i = 1; i < mxN; i++) {
		// p2[i] = p2[i - 1] * 2;
		// p2[i] %= mod;

		// p11[i] = p11[i - 1] * 11;
		// p11[i] %= mod;
		val[i] = val[i - 1] + p10 * i;
		val[i] %= mod;

		p10 *= 10;
		p10 %= mod;
	}

	// test cases
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}