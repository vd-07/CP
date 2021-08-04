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

int intersection(int l1, int r1, int l2, int r2) {
	if(l1 > l2) {
		swap(l1, l2);
		swap(r1, r2);
	}
	if(l1 == l2) {
		if(r1 > r2) {
			swap(r1, r2);		
		}
		l2 = r1;
	
	}
	if(l2 <= r1 ) {
		l2 = r1;

	}
	if(r2 < r1) {
		r2 = r1;
	}
	if(r1 == l2) {
		return r1 - l1 + r2 - l2 + 1;
	}
	
	return r1 - l1 + r2 - l2 + 2;


}

void solve() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int temp;
	for(int i = 0; i < n; i++) {
		cin >> temp;
	}

	if(n <= 2) {
		cout << n << "\n";
		return;
	}

	sort(a, a + n);
	// for(int i = 0; i < n; i++) {
	// 	cerr << i << " : " << a[i] << " ; ";
	// }

	// int total1 = 0;

	vector<int> suffix(n), prefix(n);
	int j = 0;
	for(int i = 0; i < n; i++) {
		while(a[i] - a[j] > k) j++;
		prefix[i] = i - j + 1;
	}

	j = n - 1;
	for(int i = n - 1; i >= 0; i--) {
		while(a[j] - a[i] > k) j--;
		suffix[i] = j - i + 1;
	}

	for(int i = n - 2; i >= 0; i--) {
		suffix[i] = max(suffix[i + 1], suffix[i]);
	}

	for(int i = 1; i < n; i++) {
		prefix[i] = max(prefix[i], prefix[i - 1]);
	}

	int total = 0;
	for(int i = 0; i < n - 1; i++) {
		// no clear thoughts
		total = max(total, prefix[i] + suffix[i + 1]);
	}
	
	cout << min(total, n) << "\n";
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