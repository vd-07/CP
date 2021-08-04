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

const int mxN = 3e3 + 1;

int n, k;

int gcd(int a, int b) {
	if(a == 0) {
		return b;
	}
	return gcd(b % a, a);
}


// remember for duplicates
void solve() {
	cin >> n;

	int a[n];
	int max_ele = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		max_ele = max(max_ele, a[i]);
	}

	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++) {
		v.push_back({gcd(max_ele, a[i]), a[i]});
	}

	bool mark[mxN] = {};

	int mx_gcd = max_ele;
	for(int i = 0; i < n; i++) {
		int count = 0;
		int curr_max = 0;
		int ele = -1;
		for(int i = 0; i < n; i++) {
			if(mark[a[i]]) {
				continue;
			}

			if(ele == a[i]) {
				count++;
			}

			int curr_gcd = gcd(mx_gcd, a[i]);
			if(curr_gcd > curr_max) {
				curr_max = curr_gcd;
				ele = a[i];
				count = 1;
			}
		}

		mark[ele] = true;
		while(count--) {
			cout << ele << " ";
		}
		mx_gcd = curr_max;

	}
	// int gcd = -1;
	// bool printAll = false;
	// for(int i = 1000; i >= 1; i--) {
	// 	if(printAll) {
	// 		while(count[i] > 0) {
	// 			cout << i << " ";
	// 			count[i]--;
	// 		}
	// 		continue;
	// 	}
	// 	if(count[i]) {
	// 		while(count[i]--) {
	// 			cout << i << " ";
	// 		}	
	// 		gcd = i;
	// 		// search for max gcd
	// 		for(int f = gcd - 1; f >= 1; f--) {
	// 			if(gcd % f) continue;

	// 			if(count[f]) {
	// 				gcd = f;
	// 			}

	// 			while(count[f]--) {
	// 				cout << f << " ";
	// 			}

	// 		}
	// 		printAll = true;
	// 	}
	// }
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