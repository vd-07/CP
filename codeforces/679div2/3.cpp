//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

/*

"Everyone had to be drunk on something to keep moving on. 
Everyone… was a slave to something. Even Him."

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

int n, k;
int a[6];
int b[mxN];

// vector<int> dp(mxN, -1);

int curr = INT_MAX, ma = INT_MIN, mi = INT_MAX;

void recur(int i, int mini = INT_MAX, int maxi = INT_MIN) {

	if(i == 6) {
		if(maxi - mini < curr) {
			curr = maxi - mini;
			ma = maxi;
			mi = mini;
		}
		return;
	}

	// if(dp[i] != -1) {
	// 	return dp[i];
	// }
	// every note has 6 possible choices
	// int ans = INT_MAX;
	for(int p = 0; p < 6; p++) {
		int fret = b[i] - a[p];
		recur(i + 1, min(fret, mini), max(fret, maxi));
	}

	// return dp[i] = ans;
}

void solve() {
	for(int i = 0; i < 6; i++) {
		cin >> a[i];
	}

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(a, a + 6);
	sort(b, b + n);

	set<array<int, 3>> currConfig;

	for(int i = 0; i < n; i++) {
		// make them as minimum as possible
		currConfig.insert({b[i] - a[5], i, 5});
	}

	auto calculate = [&] () {
		return ((*currConfig.rbegin())[0] - (*currConfig.begin())[0]);
	};

	int ans = INT_MAX;

	while((*currConfig.begin())[2] != 0) {
		auto [v, i, j] = *currConfig.begin();
		currConfig.erase(currConfig.begin());

		j--;
		currConfig.insert({b[i] - a[j], i, j});

		ans = min(ans, calculate());
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