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

const int mxN = 2e5 + 1;

int n;
int e[mxN], r[mxN];
int prefix[mxN];

bool ok = false;

// pair<int, int> calculate(int i, int removed_score = 0, int len = n) {
// 	if(i  > n) {
// 		if(len) {
// 			ok = true;
// 			return {0, 0};
// 		}
// 	}

// 	if(ok) {
// 		return {0, 0};
// 	}
// 	// check for issue 
	
// 	int v1 = 0, v2 = 0;
// 	int l1 = 0, l2 = 0;

// 	if(sumx < e[i] + r[i]) {
// 		v1 = 
// 		l1 = len - 1;
// 		{v2, l2} = calculate(i + 1, removed_scores + e[i], len - 1);
// 	}
// 	else {
// 		{v2, l2} = calculate(i + 1, removed_scores, len);
// 	}

// 	if(v1 == v2) {
// 		return {v1, len};
// 	}
// 	else {
// 		return v1 > v2 ? {v1, l1} : {v2, l2};
// 	}

// }

void solve() {
	cin >> n;

	prefix[0] = 0;

	for(int i = 1; i <= n; i++) {
		
		cin >> e[i] >> r[i];
		prefix[i] = e[i] + prefix[i - 1];
	}

	ok = false;

	int removed_score = 0;
	int score = 0;
	int len = n;

	int removed_len = 0;


	for(int i = 1; i <= n; i++) {

		int sumx = prefix[n] - removed_score;

		// debug(sumx, e[i] + r[i], removed_score);

		if(sumx < e[i] + r[i]) {


			int newscore = sumx + prefix[i - 1] - removed_score;

			// debug(score, newscore);

			if(newscore > score) {
				score = newscore;
				len = n - removed_len;
			}
			else if(newscore == score) {
				len = max(len, n - removed_len);
			}
			// debug(score, newscore);
			// updates
			removed_len++;
			removed_score += e[i];
		}
	}

	// debug(removed_len);

	if(checkForIndefinite()) {
		cout << "0 " << "INDEFINITELY\n";
	}
	else {
		cout << n - len << " " << score << "\n";
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


	// test cases
	int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #"<< i << ": ";
        solve();
    }

	return 0;
}