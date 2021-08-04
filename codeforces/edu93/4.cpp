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

vector<int> A(3);
const int mxN = 205;
int sticks[3][mxN];
int dp[mxN][mxN][mxN];

int calculate(vector<int> a) {
	int ans = 0;
	if(dp[a[0]][a[1]][a[2]] != -1)
		return dp[a[0]][a[1]][a[2]];
	for(int i = 0; i < 3; i++) {
		for(int j = i + 1; j < 3; j++) {
			if(A[i] == a[i] || A[j] == a[j]) {
				continue;
			}
			debug(ans, a[i], a[j]);
			ans = max(ans, sticks[i][a[i]++] * sticks[j][a[j]++] + calculate(a));
			debug(ans, a[i], a[j]);
			a[i]--, a[j]--;
		}
	}
	return dp[a[0]][a[1]][a[2]] = ans;
}

void solve() {
	cin >> A[0] >> A[1] >> A[2];
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < A[i]; j++) {
			cin >> sticks[i][j];
		}
	}
	sort(sticks[0], sticks[0] + A[0], greater<>());
	sort(sticks[1], sticks[1] + A[1], greater<>());
	sort(sticks[2], sticks[2] + A[2], greater<>());
	vector<int> a(3);
	for(int i = 0; i < mxN; i++) {
		for(int j = 0;j < mxN; j++) {
			for(int k = 0; k < mxN; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	cout << calculate(a);
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