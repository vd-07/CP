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
int a[mxN];

void solve() {
	cin >> n;

	vector<int> ans(n);

	char c;

	int shuriken;
	
	n *= 2;

	stack<pair<int, int>> left; // index and curr_max

	int idx = 0;

	bool ok = true;
	int prev = -1;

	while(n--) {
		cin >> c;
		if(c == '+') {
			left.push({idx++, -1});
			prev = -1;
		}
		else {
			cin >> shuriken;

			check for continuously increasing
			if(prev == -1) {
				prev = shuriken;
			}
			else {
				if(shuriken < prev) {
					ok = false;
					continue;
				}
			}

			if(left.empty()) {
				ok = false;
				continue;
			}

			auto [i, curr_max] = left.top();

			left.pop();

			ans[i] = shuriken;

			prev = shuriken;

			if(curr_max == -1) {
				curr_max = shuriken;
			}
			else {
				if(curr_max > shuriken) {
					ok = false;
					continue;
				}
			}

			curr_max = min(curr_max, shuriken);

			if(!left.empty()) {
				if(left.top().second == -1) {
					left.top().second = curr_max;
				}
				// left.top().second = min(left.top().second, curr_max);
			}

		}
	}

	if(ok) {
		cout << "YES\n";
		for(int i : ans) {
			cout << i << " " ;
		}
	}
	else {
		cout << "NO";
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
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}