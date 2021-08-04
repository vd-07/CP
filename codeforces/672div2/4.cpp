//Author : Vivek Dubey
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
using namespace __gnu_pbds; //required 
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 

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
pair<int, int> range[mxN];
int factorial[mxN];

// int recur(int lo, int hi, int pos = 0, int count = 0) {
// 	if(count == k) {
// 		return 1;
// 	}
// 	if(pos == n) {
// 		return 0;
// 	}
// 	// either select or not select
// 	int ans = recur(lo, hi, pos + 1, count) % mod;
// 	int curr_l = max(lo, l[pos]);
// 	int curr_r = min(hi, r[pos]);

// 	if(curr_l >= lo && curr_l <= hi && curr_r >= lo && curr_r <= hi) {
// 		ans += recur(curr_l, curr_r, pos + 1, count + 1);
// 		ans %= mod;
// 	}

// 	return ans;
// }

int power(int base, int ep) {
	int res = 1;
	while(ep) {
		if(ep & 1) {
			res *= base;
			res %= mod;
		}
		base *= base;
		base %= mod;

		ep /= 2;	
	}
	return res;
}

int modInverse(int num) {
	return power(num, mod - 2) % mod;
}

int calcNcr(int n, int r) {
	if(n < r) {
		return 0;
	}
	int num = factorial[n];
	int den = factorial[r] * factorial[n - r];
	den %= mod;

	int ans = (num * modInverse(den) )% mod;
	debug(n, r, ans);
	return ans;
}

void solve() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> range[i].first >> range[i].second;
	}
	// cout << recur(1, 1e9);
	if(k == 1) {
		cout << n;
		return;
	}

	sort(range, range + n);
	int ans = 0;

	ordered_set<int> s;

	s.insert(range[0].second);
	for(int i = 1; i < n; i++) {
		int count = s.order_of_key(range[i].first);
		

		count = (int)s.size() - count;

		ans += calcNcr(count, k - 1);
		ans %= mod;

		s.insert(range[i].second);
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

	factorial[0] = 1;
	for(int i = 1; i < mxN; i++) {
		factorial[i] = factorial[i - 1] * i;
		factorial[i] %= mod;
	}

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