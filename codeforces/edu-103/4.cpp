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

string s;

// its freezing cold

void recur(int node, vector<vector<int>> &dp) {

	int ans = 1;

	vector<pair<int, int>> toAssign;

	// go right
	int second = 0;
	int city = node;

	while(true) {
		toAssign.push_back({city, second});
		if(second) {
			if(city != n) {
				if(s[city] == 'L') {
					ans += 1;
				} else {
					break;
				}
			} else {
				break;
			}	
		} else {
			if(city != n) {
				if(s[city] == 'R') {
					ans += 1;
				} else {
					break;
				}
			} else {
				break;
			}
		}
		

		second++;
		second %= 2;

		city++;
	}

	// go left
	second = 0;
	city = node;
	while(true) {
		toAssign.push_back({city, second});

		if(second) {
			if(city != 0) {
				if(s[city - 1] == 'R') {
					ans += 1;
				} else {
					break;
				}
			} else {
				break;
			}
		} else {
			if(city != 0) {
				if(s[city - 1] == 'L') {
					ans += 1;
				} else {
					break;
				}
			} else {
				break;
			}
		}

		second++;
		second %= 2;

		city--;
	}

	for(pair<int, int> i : toAssign) {
		dp[i.first][i.second] = ans;
	}


	// if(second) {
	// 	// opposite
	// 	// going right
	// 	if(city != n) {
	// 		if(s[city] == 'L') {
	// 			ans += 1 + recur(city + 1, 0, dp);
	// 		}
	// 	} 
	// 	// going left
	// 	if(city != 0) {
	// 		if(s[city - 1] == 'R') {
	// 			ans += 1 + recur(city - 1, 0, dp);
	// 		}
	// 	}
	// } else {
	// 	// going right
	// 	if(city != n) {
	// 		if(s[city] == 'R') {
	// 			ans += 1 + recur(city + 1, 1, dp);
	// 		}
	// 	} 
	// 	// going left
	// 	if(city != 0) {
	// 		if(s[city - 1] == 'L') {
	// 			ans += 1 + recur(city - 1, 1, dp);
	// 		}
	// 	}
	// }

	// return dp[city][second] = ans;
}

void solve() {
	cin >> n;

	vector<vector<int>> dp(n + 1, vector<int> (2, 0));

	cin >> s;

	for(int i = 0; i <= n; i++) {
		if(dp[i][0]) {
			cout << dp[i][0] << " ";
		} else {
			recur(i, dp);
			cout << dp[i][0] << " ";
		}
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