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
int a[mxN];

int findCost(int b, vector<int> &p) {
	if(b <= 0) {
		return 0;
	}

	int res = INT_MAX;

	int lo = 0, hi = (int)p.size() - 1;

	if(p.empty()) {
		return INT_MAX;
	}

	debug(p);

	while(lo <= hi) {
		int mid = (lo + hi) / 2;

		if(p[mid] >= b) {
			hi = mid - 1;
			res = mid + 1;
		} else {
			lo = mid + 1;
		}
	}

	return res;
}
void solve() {
	// either 1 done
	// either 2 done
	// both ?
	// cost of 2 1s = 2
	// if m1i + m1j >= m2k select 1's
	// if 

	// the thing is selecting only the greatest ones from both the sets will yield optimal
	// kinda like selecting two prefix indexes from both the sets to minimize 2 * i + j
	// and p[i] + q[j] >= m

	// o(n^2)

	// if i fix j and find corresponding i using bs
	// o(nlogn)

	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> p, q;

	int b;
	for(int i = 0; i < n; i++) {
		cin >> b;
		if(b == 1) {
			q.push_back(a[i]);
		} else {
			p.push_back(a[i]);
		}
	}
	sort(q.rbegin(), q.rend());
	sort(p.rbegin(), p.rend());

	for(int i = 1; i < p.size(); i++) {
		p[i] += p[i - 1];
	}

	for(int i = 1; i < q.size(); i++) {
		q[i] += q[i - 1];
	}

	int cost = 0 + 2 * findCost(m, p);

	for(int i = 0; i < q.size(); i++) {
		cost = min(cost, i + 1 + 2 * findCost(m - q[i], p));
	}

	cost = min(cost, 0 + findCost(m, q));

	for(int i = 0; i < p.size(); i++) {
		cost = min(cost, (i + 1) * 2 + findCost(m - p[i], q));
	}

	if(cost > 1e9) {
		cost = -1;
	}

	cout << cost << "\n";
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