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

const int mxN = 1e2 + 1;

int n, m;
int a[mxN][mxN];

vector<vector<pair<int, int>>> ans;

void printMatrix() {
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
	
}

void changeValue(vector<pair<int, int>> op) {
	ans.push_back(op);
	for(pair<int, int> p : op) {
		int x = p.first, y = p.second;
		a[x][y] = 1 - a[x][y];
	}
}

vector<int> moves[4];

bool check(vector<int> values, vector<int> op) {
	for(int i = 0; i < 4; i++) {
		if(op[i]) {
			for(int j = 0; j < 4; j++) {
				if(moves[i][j]) {
					values[j] ^= 1;
				}
			}
		}
	}

	for(int i = 0; i < 4; i++) {
		if(values[i]) {
			return false;
		}
	}
	return true;
}

void changeValue(vector<pair<int, int>> c, vector<int> op) {
	for(int i = 0; i < 4; i++) {
		vector<pair<int, int>> temp;
		if(op[i]) {
			for(int j = 0; j < 4; j++) {
				if(moves[i][j]) {
					temp.push_back({c[j]});
				}
			}	
		}
		if(!temp.empty()) {
			changeValue(temp);
		}
	}
}

void perform2(int x, int y) {
	vector<pair<int, int>> coordinates = {{x, y}, {x + 1, y}, {x, y + 1}, {x + 1, y + 1}};
	vector<int> values = {a[x][y], a[x + 1][y], a[x][y + 1], a[x + 1][y + 1]};

	// select none, 1, 2, 3 , all	
	// [0], [1], [2], [3], [0, 1], [0, 2], [0, 3], [1, 2], [1, 3], [1, 2, 3], [1, 2, 4], [2, 3, 4], [1, 2, 3, 4]

	for(int select = 0; select < (1 << 4); select++) {
		vector<int> op;
		int selected = select;
		while(selected) {
			op.push_back(selected % 2);
			selected /= 2;
		}
		while(op.size() < 4) {
			op.push_back(0);
		}
		if(check(values, op)) {
			changeValue(coordinates, op);
			break;
		}
	}

}

void perform1(int x, int y) {
	if(y + 1 <= m) {
		vector<pair<int, int>> temp = {{x, y}, {x + 1, y}, {x + 1, y + 1}};
		changeValue(temp);
	} else {
		vector<pair<int, int>> temp = {{x, y}, {x + 1, y}, {x + 1, y - 1}};
		changeValue(temp);
	}
}

void solve() {
	cin >> n >> m;

	ans.clear();

	char c;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> c;
			a[i][j] = c - '0';
		}
	}

	for(int i = 1; i <= n - 2; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j]) {
				// just remove current 1
				perform1(i, j);
				// debug(i, j);
			}
		}
	}

	if(m & 1) {
		if(a[n - 1][m]) {
			vector<pair<int, int>> temp = {{n - 1, m}, {n - 1, m - 1}, {n, m - 1}};
			changeValue(temp);
		}
		if(a[n][m]) {
			vector<pair<int, int>> temp = {{n, m}, {n - 1, m - 1}, {n, m - 1}};
			changeValue(temp);
		}
	}
	
	for(int j = 1; j <= m - 1; j += 2) {
		// look for square with diagonal n - 1, j to n, j + 1
		// use 4 operations to make all zeros 
		
		perform2(n - 1, j);
		

	}

	// printMatrix();

	cout << ans.size() << "\n";
	for(vector<pair<int, int>> p : ans) {
		for(pair<int, int> pp : p) {
			cout << pp.first << " " << pp.second << " ";
		}
		cout << "\n";
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

	moves[0] = {0, 1, 1, 1};
	moves[1] = {1, 0, 1 , 1};
	moves[2] = {1, 1, 0, 1};
	moves[3] = {1, 1, 1, 0};

	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}