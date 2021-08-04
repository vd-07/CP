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
	#define pb push_back

const int mxN = 3e5 + 1;

bool matrix[10][2 * 10 - 1];
int ra, pa, rb, pb, c;
int s;
int score = INT_MIN;

bool check(int x, int y) {
	return x > 0 && x <= s && y > 0 && y <= (2 * x - 1) && matrix[x][s - x + y];
}

vector<pair<int, int>> calc(int x, int y) {
	vector<pair<int, int>> coord;

	int nx, ny;

	nx = x, ny = y - 1;
	if(check(nx, ny)) {
		coord.push_back({nx, ny});
	}

	nx = x, ny = y + 1;
	if(check(nx, ny)) {
		coord.push_back({nx, ny});
	}

	if((x + y) & 1) {
		nx = x - 1, ny = y - 1;
	}
	else {
		nx = x + 1, ny = y + 1;
	}

	if(check(nx, ny)) {
		coord.push_back({nx, ny});
	}
	return coord;
}

int dfs(int x1, int y1, int x2, int y2, bool chance, int mark = 0) {
	int ct = 0;

	if(mark >= 3) {
		return 0;
	}

	int px, py;

	if(mark != 1 && (chance || (mark == 2))) {
		// alma
		ct = INT_MIN;
		vector<pair<int, int>> neighbours = calc(x1, y1);

		// debug(neighbours);

		if(neighbours.empty()) {
			return dfs(x1, y1, x2, y2, false, mark + 1);
		}

		for(pair<int, int> coord:neighbours) {
			int x = coord.first, y = coord.second;
			y = s - x + y;
			if(matrix[x][y]) {
				matrix[x][y] = false;
				if(ct <= dfs(coord.first, coord.second, x2, y2, false, mark) + 1) {
					ct = dfs(coord.first, coord.second, x2, y2, false, mark) + 1;
					px = x, py = y;
				}
				matrix[x][y] = true;
			}
		}
	}

	if(mark != 2 && (!chance || mark == 1)) {
		ct = INT_MAX;
		vector<pair<int, int>> neighbours = calc(x2, y2);

		// debug(neighbours, matrix[2][2]);

		if(neighbours.empty()) {
			return dfs(x1, y1, x2, y2, true, mark + 2);
		}

		for(pair<int, int> coord:neighbours) {
			int x = coord.first, y = coord.second;
				y = s - x + y;
			if(matrix[x][y]) {
				matrix[x][y] = false;
				if(ct >= dfs(x1, y1, coord.first, coord.second, true, mark) - 1) {
					ct = dfs(x1, y1, coord.first, coord.second, true, mark) - 1;
					px = x;
					py = y;
				}
				
				matrix[x][y] = true;
			}
		}
	}

	// matrix[px][py] = false;

	return ct;
}

void solve() {
	for(int i = 0; i < 7; i++) {
		for(int j = 0; j < 13; j++) {
			matrix[i][j] = false;
		}
	}

	cin >> s >> ra >> pa >> rb >> pb >> c;

	for(int i = 1; i <= s; i++) {
		for(int j = 1; j <= 2 * i - 1; j++) {
			int x = s - i + j;
			matrix[i][x] = true;
		}
	}

	int x, y;

	for(int i = 1; i <= c; i++) {
		cin >> x >> y;
		matrix[x][s - x + y] = false;
	}

	matrix[ra][s - ra + pa] = false;
	matrix[rb][s - rb + pb] = false;

	cout << dfs(ra, pa, rb, pb, true) << "\n";
}

int32_t main() {
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
		freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    //this can be opted out if you want to print the output to the sublime console
		freopen("output.txt", "w", stdout);
	#endif

	int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #"<< i << ": ";
        solve();
    }

	return 0;
}