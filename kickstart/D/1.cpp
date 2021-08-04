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
	 
	#ifdef CODINGINVEINS
	#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
	#else
	#define debug(...) 42
	#endif
// end debug

#define int long long

const int mxN = 3e5 + 1;

int n;
vector<vector<int>> mat(3, vector<int> (3));

int calc() {	
	// rows
	int count = 0;

	for(int i = 0; i < 3; ++ i) {
		if(mat[i][0] + mat[i][2] == 2 * mat[i][1]) {
			++ count;
		}
	}

	// cols
	for(int i = 0; i < 3; ++ i) {
		if(mat[0][i] + mat[2][i] == 2 * mat[1][i]) {
			++ count;
		}
	}	

	// diagonals
	count += (2 * mat[1][1] == (mat[0][0] + mat[2][2]));

	count += (2 * mat[1][1] == (mat[0][2] + mat[2][0]));

	debug(mat, count);

	return count;
}

void solve() {
	

	for(int i = 0; i < 3; ++ i) {
		for(int j = 0; j < 3; ++ j) {
			if(i != 1 || j != 1) {
				cin >> mat[i][j];		
			}
		}
	}

	int ans = 0;

	mat[1][1] = (mat[0][0] + mat[2][2]) / 2;

	ans = max(ans, calc());

	mat[1][1] = (mat[0][2] + mat[2][0]) / 2;

	ans = max(ans, calc());

	mat[1][1] = (mat[0][0] + mat[2][2]) / 2;

	ans = max(ans, calc());

	mat[1][1] = (mat[0][1] + mat[2][1]) / 2;

	ans = max(ans, calc());

	mat[1][1] = (mat[1][0] + mat[1][2]) / 2;

	ans = max(ans, calc());

	cout << ans << "\n";
}

int32_t main() {
	#ifdef CODINGINVEINS
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
	for(int i = 1; i <= t; i++) {
        cout << "Case #"<< i << ": ";
        solve();
    	}
	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif

	return 0;
}