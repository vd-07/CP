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
int a[mxN];

int calc(int s, int e) {
	int sum = 0;
	for(int i = s + 1; i < e; i++) {
		if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
			sum++;
		}
		if(a[i] < a[i - 1] && a[i] < a[i + 1]) {
			sum++;
		}
	}
	return sum;
}

void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sum = 0;

	vector<int> hills;

	for(int i = 1; i < n - 1; i++) {
		if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
			sum++;
			hills.push_back(i);
		}
		if(a[i] < a[i - 1] && a[i] < a[i + 1]) {
			sum++;
			hills.push_back(i);
		}
	}

	// debug(hills);

	// for(int i = 1; i < hills.size(); i++) {
	// 	if(hills[i] == hills[i - 1] + 2) {
	// 		sum --;
	// 		cout << sum << "\n";
	// 		return;
	// 	}
	// }	

	// for(int i = 1; i < valleys.size(); i++) {
	// 	if(valleys[i] == valleys[i - 1] + 2) {
	// 		sum --;
	// 		cout << sum << "\n";
	// 		return;
	// 	}
	// }	

	int ans = sum;

	for(int i : hills) {
		// change a[i]
		int earlier = 0;

		int j = max(i - 2, 0ll);
		int k = min(i + 2, n - 1);

		int o1 = calc(j, k);

		int changedValue = a[i];

		a[i] = a[i - 1];

		int o2 = calc(j, k);

		a[i] = a[i + 1];

		int o3 = calc(j, k);

		a[i] = changedValue;

		ans = min({ans, sum - o1 + o2, sum - o1 + o3});

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