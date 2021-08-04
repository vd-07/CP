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

const int mxn = 1e5 + 100;

int n;
int t[mxn], x[mxn];

void solve() {
	cin >> n;

	int ans = 0;

	for(int i = 0; i < n; i++) {
		cin >> t[i] >> x[i];
	}

	// where is the robot
	int curr = 0, dest = x[0], ct = t[0];

	t[n] = 2e18;

	for(int i = 0; i < n; i++) {
		if(t[i] >= ct + abs(dest - curr)) {
			// arrived and waiting
			curr = dest;
			dest = x[i];
			ct = t[i];
		}
		// if(t[i] < t + dest) {
		// 	// will ignore the command
		// 	// will robot reach x[i] on or before t[i + 1]
		int xs = curr + (t[i] - ct) * (curr < dest ? 1 : -1);
		int xr = curr + (t[i + 1] - ct) * (curr < dest ? 1 : -1);

		debug(i, xs, xr, curr, dest, ct);

		// may have finised the journey in the mid
		if(curr < dest) {
			// travelling in pos direction
			xr = min(xr, dest);
			// if(i == n - 1) {
			// 	xr = 2e9;
			// }
		} else {
			xr = max(xr, dest);
			// if(i == n - 1) {
			// 	xr = -2e9;
			// }
		}

		debug(i, xs, xr);

		if(xs > xr) {
			swap(xs, xr);
		}

		if(xs <= x[i] && x[i] <= xr) {
			debug(i);
			ans ++;
		}
		// }

		// if time is greater than wait time
		// accept the command
		
	}
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
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}