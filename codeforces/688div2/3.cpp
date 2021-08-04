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

int n;

struct Coordinates {
	int X, Y;
};

struct Digits {
	vector<Coordinates> sY, bY, sX, bX;
};

void check(Digits &d, int x, int y) {
	if(d.sX.empty() || d.sX.back().X == x) {
		d.sX.push_back({x, y});
	} else if (d.sX.back().X > x) {
		d.sX.clear();
		d.sX.push_back({x, y});
	}

	if(d.bY.empty() || d.bY.back().Y == y) {
		d.bY.push_back({x, y});
	} else if(d.bY.back().Y < y) {
		d.bY.clear();
		d.bY.push_back({x, y});
	}

	if(d.bX.empty() || d.bX.back().X == x) {
		d.bX.push_back({x, y});
	} else if(d.bX.back().X < x) {
		d.bX.clear();
		d.bX.push_back({x, y});
	}

	if(d.sY.empty() || d.sY.back().Y == y) {
		d.sY.push_back({x, y});
	} else if(d.sY.back().Y > y) {
		d.sY.clear();
		d.sY.push_back({x, y});	
	}
}

int maxValue(vector<Coordinates> &v) {
	int ans = 0;
	for(Coordinates i : v) {
		for(Coordinates j : v) {
			ans = max(ans, (abs(i.X - j.X)) * (max({i.Y, j.Y, n - i.Y - 1, n - j.Y - 1})));
			ans = max(ans, (abs(i.Y - j.Y)) * (max({i.X, j.X, n - i.X - 1, n - j.X - 1})));
			debug(i.X, i.Y, j.X, j.Y, ans);
		}
	}
	return ans;
}

int calculateValues(vector<vector<int>> &v, int d) {
	Digits digit;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(v[i][j] == d) {
				check(digit, i, j);
			}
		}
	}

	vector<Coordinates> finalValue;

	for(Coordinates i : digit.sX) {
		finalValue.push_back(i);
	}

	for(Coordinates i : digit.sY) {
		finalValue.push_back(i);
	}

	for(Coordinates i : digit.bX) {
		finalValue.push_back(i);
	}

	for(Coordinates i : digit.bY) {
		finalValue.push_back(i);
	}

	debug(d);
	return maxValue(finalValue);
}

void solve() {
	cin >> n;

	vector<vector<int>> v(n, vector<int> (n));
	vector<vector<int>> values(10, {0, n, 0, n});
	// max-row, min-row, max-col, min-col

	char c;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> c;
			v[i][j] = c - '0';

			int d = v[i][j];

			values[d][0] = max(values[d][0], i);
			values[d][2] = max(values[d][2], j);
			values[d][1] = min(values[d][1], i);
			values[d][3] = min(values[d][3], j);
		}
	}

	vector<int> ans(10);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int d = v[i][j];

			ans[d] = max(ans[d], max(i, n - i - 1) * max(values[d][2] - j, j - values[d][3]));
			ans[d] = max(ans[d], max(j, n - j - 1) * max(values[d][0] - i, i - values[d][1]));
		}
	}

	for(int i = 0; i < 10; i++) {
		cout << ans[i] << " ";
	}

	cout << "\n";

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