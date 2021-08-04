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

int n;

int query(int l, int r) {
	cout << "? " << l << " " << r << endl;
	int ans;
	cin >> ans;
	return ans; 
}

int searchBack(int mid, int r) {
	int curr = r;
	int ans = n;
	for(int i = (r - mid) / 2; i; i /= 2) {

		if(curr <= mid) {
			return mid + 1;
		}

		int idx = query(mid, curr);

		if(idx == mid) {
			// still in the search space
			// reduce the search space
			ans = curr;
			curr -= i;
		} else {
			curr += i;
		}

	}

	return curr;
}

int searchFront(int l, int mid) {

	int curr = l;
	int ans = 1;
	for(int i = (mid - l) / 2; i; i /= 2) {	
		if(curr >= mid) {
			return mid - 1;
		}

		int idx = query(curr, mid);

		if(idx == mid) {
			// still in the search space
			// reduce the search space
			ans = curr;
			curr += i;
		} else {
			curr -= i;
		}

	}

	return curr;
}

int findAnsFront(int ans, int mid) {
	int idx = query(ans, mid);
	if(idx == mid) {
		if(ans == 1) {
			return 1;
		}
		idx = query(ans - 1, mid);
		if(idx == mid) {
			return ans - 1;
		} else {
			return ans;
		}
	} else {
		return ans - 1;
	}
	
	if(ans != mid)
	return ans + 1;
	return ans;
}

int findAnsBack(int mid, int ans) {
	int idx = query(mid, ans);
	if(idx == mid) {
		if(ans == n) {
			return n;
		}
		idx = query(mid, ans + 1);
		if(idx == mid) {
			return ans + 1;
		} else {
			return ans;
		}
	} else {
		return ans + 1;
	}

	if(ans - 1 != mid)
	return ans - 1;
	return ans;
}

void solve() {
	cin >> n;

	int mid = query(1, n);

	if(n == 2) {
		if(mid == 1) {
			cout << "! 2\n";
		} else {
			cout << "! 1\n";
		}
		return;
	}
	// check for search partition

	int m1, m2;

	m1 = query(1, mid);

	// cout << "? " << mid << " " << n << endl;

	// cin >> m2;

	if(mid == m1) {
		int ans = searchFront(1, mid);
		cout << "! " << ans ;
	} else {
		int ans = searchBack(mid, n);
		cout << "! " << ans ;
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