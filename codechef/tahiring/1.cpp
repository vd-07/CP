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

const int mxN = 2e5 + 1;

int n, q;
int quality[mxN], quantity[mxN];

int highest[mxN];

void buildTree(int id = 1, int l = 0, int r = n - 1) {
	if(l == r) {
		highest[id] = quality[l];
	}
	else {
		int mid = (l + r) / 2;
	}
}

int queryTree(int l, int r) {
	l += n;
	r += n;
	int ans = INT_MIN;
	while(l < r) {
		if(l & 1) {
			ans = max(ans, highest[l++]);
		} else if(r & 1) {
			ans = max(ans, highest[r--]);
		}
		l /= 2;
		r /= 2;
	}
	return ans;
}

void solve() {
	cin >> n >> q;

	map<int, int> idx;
	for(int i = 0; i < n; i++) {
		cin >> quality[i];
		highest[i] = quality[i];
		idx[quality[i]] = i;
	}
	buildTree();

	for(int i = 0; i < n; i++) {
		cin >> quantity[i];
	}

	int type;
	while(q--) {
		cin >> type;
		if(type == 1) {
			int l, r, qt;
			cin >> l >> r >> qt;
			int id = idx[queryTree(l - 1, r - 1)];

			quantity[id] += qt;
		}
		else {
			int v, i, qt, thr;
			cin >> v >> i >> qt >> thr;
			int l = max(1ll, i - v);
			int r = min(n, i + v);
			int maxQt = queryTree(l - 1, r - 1);
			int id = idx[maxQt];
			debug(id, maxQt, quantity[id]);
			if(maxQt < thr || quantity[id] < qt) {
				cout << "no purchase\n";
				continue;
			}
			cout << id << "\n";
			quantity[id] -= qt;
		}
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
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}