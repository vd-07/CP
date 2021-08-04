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

int n, k;

int scores(int r1, int s1, int p1, int r2, int s2, int p2) {
	int score = 0;

	// remove draws


	int t1 = min(r1, r2);
	r1 -= t1;
	r2 -= t1;

	int t2 = min(s1, s2);
	s1 -= t2;
	s2 -= t2;

	int t3 = min(p1, p2);
	p1 -= t3;
	p2 -= t3;

	score += min(r1, s2);
	
	score += min(s1, p2);
	
	score += min(p1, r2);

	return score;
}

int draw(int r1, int s1, int p1, int r2, int s2, int p2) {
	// int t1 = min(r1, s2);
	// int t2 = min(s1, p2);
	// int t3 = min(p1, r2);

	int score = 0;

	score += min(p1, p2);
	score += min(r1, r2);
	score += min(s1, s2);

	return score;
}

int calculate(int r1, int s1, int p1, int r2, int s2, int p2, bool ok) {
	int score = 0;

	int t1 = min(r1, s2);
	score += t1;

	int t2 = min(s1, p2);
	score += t2;

	int t3 = min(p1, r2);
	score += t3;

	int s = 0;
	if(ok) {

		// first win and then draw
		int a1 = r1 - t1;
		int a2 = s1 - t2;
		int a3 = p1 - t3;

		int b1 = r2 - t3;
		int b2 = s2 - t1;
		int b3 = p2 - t2;

		score += draw(a1, a2, a3, b1, b2, b3);

		// first draw and then win
		s += draw(r1, s1, p1, r2, s2, p2);
		s += scores(r1, s1, p1, r2, s2, p2);

		return max(s, score);
	}

	return score;
}


void solve() {
	cin >> n;

	int a1, a2, a3;
	int b1, b2, b3;

	cin >> a1 >> a2 >> a3;
	cin >> b1 >> b2 >> b3;

	// max times alice can win

	int m2 = calculate(a1, a2, a3, b1, b2, b3, false);
	int m1 = n - calculate(b1, b2, b3, a1, a2, a3, true);

	cout << m1 << " " << m2;

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