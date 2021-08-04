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

const int N = 1e3 + 10;

int r, c;
vector<vector<int>> grid;
vector<vector<int>> dphp, dphs, dpvp, dpvs;

void build() {
	for(int i = 0; i < c; i++) {
		dpvp[0][i] = grid[0][i];
		for(int j = 1; j < r; j++) {
			if(grid[j][i]) {
				dpvp[j][i] = dpvp[j - 1][i] + grid[j][i];	
			} 
		}
	}

	for(int i = 0; i < c; i++) {
		dpvs[r - 1][i] = grid[r - 1][i];
		for(int j = r - 2; j >= 0; j--) {
			if(grid[j][i]) {
				dpvs[j][i] = dpvs[j + 1][i] + grid[j][i];	
			} 
		}
	}

	for(int i = 0; i < r; i++) {
		dphp[i][0] = grid[i][0];
		for(int j = 1; j < c; j++) {
			if(grid[i][j]) {
				dphp[i][j] = dphp[i][j - 1] + grid[i][j];	
			} 
		}	
	}

	for(int i = 0; i < r; i++) {
		dphs[i][c - 1] = grid[i][c - 1];
		for(int j = c - 2; j >= 0; j--) {
			if(grid[i][j]) {
				dphs[i][j] = dphs[i][j + 1] + grid[i][j];	
			} 
		}	
	}	

}

int find(int x, int y) {
	if(x < 2 || y < 2) {
		return false;
	}
	return min(x, y / 2) - 2 + min(x / 2, y);
}

int count() {
	int ans = 0;
	
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			ans += find(dphp[i][j], dpvp[i][j]);
			ans += find(dphp[i][j], dpvs[i][j]);
			ans += find(dphs[i][j], dpvp[i][j]);
			ans += find(dphs[i][j], dpvs[i][j]);
		}
	}

	return ans;
}

void solve() {
	cin >> r >> c;

	grid = vector<vector<int>> (r, vector<int> (c));

	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}

	dphp = vector<vector<int>> (r, vector<int> (c));
	dphs = vector<vector<int>> (r, vector<int> (c));
	dpvp = vector<vector<int>> (r, vector<int> (c));
	dpvs = vector<vector<int>> (r, vector<int> (c));

	build();

	int ans = count();

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
	int t;
    	cin >> t;
    	for(int i = 1; i <= t; i++) {
        cout << "Case #"<< i << ": ";
        solve();
    	}

	return 0;
}