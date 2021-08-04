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

int n, m;

int findAns(vector<int> a, vector<int> b) {
	// construct consecutive array

	// consecutive_count, last point

	int n = a.size(), m = b.size();

	if(m == 0 || n == 0) {
		return 0;
	}

	vector<int> already(n + 1);

	for(int i = n - 1; i >= 0; i--) {
		auto itr = lower_bound(b.begin(), b.end(), a[i]);

		if(itr != b.end()) {
			if(*itr == a[i]) {
				already[i] = 1;
			}
		}

		already[i] += already[i + 1];
	}

	int ans = already[0];

	for(int i = 0; i < n; i++) {
		int start = a[i];
		int end;

		if(i < n - 1) {
			end = a[i + 1];
		} else {
			end = b[m - 1] + 1;
		}

		start = lower_bound(b.begin(), b.end(), start) - b.begin();
		end = lower_bound(b.begin(), b.end(), end) - b.begin();


		// iterate over points within ls of length i

		int count = 0;

		for(int j = start; j < end; j++) {
			// start pos is j, end pos is j + i atmax

			int currStart = upper_bound(b.begin(), b.end(), b[j] - i - 1) - b.begin();
			debug(currStart, j);
			count = max(count, j - currStart + 1);
		}

		count = min(count, i + 1);

		ans = max(ans, count + already[i + 1]);

		debug(ans, i, count, start, end);
	}

	debug(ans);

	return ans;

}

void solve() {
	cin >> n >> m;

	vector<int> posBox, posPoint, negBox, negPoint;

	for(int i = 1; i <= n; i++) {
		int box;
		cin >> box;
		if(box < 0) {
			negBox.push_back(-box);
		} else {
			posBox.push_back(box);
		}
	}

	for(int i = 1; i <= m; i++) {
		int point;
		cin >> point;
		if(point < 0) {
			negPoint.push_back(-point);
		} else {
			posPoint.push_back(point);
		}
	}

	reverse(negPoint.begin(), negPoint.end());
	reverse(negBox.begin(), negBox.end());

	int pos = findAns(posBox, posPoint);
	int neg = findAns(negBox, negPoint);

	debug(pos, neg);

	int ans = pos + neg;

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