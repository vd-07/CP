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

const int mxN = 3e3 + 1;

const int mod = 1e9 + 7;

int n, k;
int a[mxN];

int power(int base, int expo) {
	int res = 1;

	while(expo) {
		if(expo & 1) {
			res = (res * base) % mod;
		}
		base = (base * base) % mod;

		expo /= 2;
	}

	return res;
}

int inverseMod(int num) {
	return power(num, mod - 2);
}

int combi(int n, int r) {
	int factN = 1, factR = 1;

	int nr = n - r;

	int factNR = 1;

	while(n) {
		factN *= n;
		factN %= mod;
		n--;
	}

	while(r) {
		factR *= r;
		factR %= mod;
		r--;
	}

	while(nr) {
		factNR *= nr;
		factNR %= mod;
		nr--;
	}
	
	debug(factN, factR, factNR);

	factR *= factNR;
	factR %= mod;

	int ans = factN * inverseMod(factR);

	return ans %= mod;
}

void solve() {
	cin >> n >> k;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	reverse(a, a + n);

	// ways will change only if the kth element is repeated

	// if there is an option in greater no, then selecting that greater no instead of a smaller 
	// will result in greater no of followers

	// if there is repeation of smallest no before (including) kth element = p
	// after = q
	// p + q = n C p

	int p = 0, q = 0;

	int small = a[k - 1];

	for(int i = 0; i < k; i++) {
		if(a[i] == small) {
			p++;
		}
	}

	for(int i = k; i < n; i++) {
		if(a[i] == small) {
			q++;
		}
	}

	int res = combi(p + q, p);

	cout << res << "\n";
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
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}