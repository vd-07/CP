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

int calculate(string s) {
	int score = 0;

	bool ok = false;

	for(char c : s) {
		if(c == 'W') {
			score += (ok ? 2 : 1);
			ok = true;
		}
		else {
			ok = false;
		}
	}
	return score;
}

int firstW(string s) {
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'W')
			return i;
	}
	return s.size();
}

int lastW(string s) {
	for(int i = s.size() - 1; i >= 0; i--) {
		if(s[i] == 'W') {
			return i;
		}
	}
	return 0;
}

void solve() {
	cin >> n >> k;
	string s;
	cin >> s;

	vector<pair<int, int>> v;

	// find distance between two W, sort and fill

	int ct = 0;
	bool notfirst = false;
	for(int i = 0; i < n; i++) {

		if(s[i] == 'W') {
			if(ct && notfirst) {
				v.push_back({ct, i - ct});
			}
			ct = 0;
			notfirst = true;
		}
		else if(s[i] == 'L') {
			ct++;
		}
	}

	sort(v.begin(), v.end());

	for(pair<int, int> p : v) {
		int i = p.second;
		while(p.first-- && k > 0) {
			s[i++] = 'W';
			k--;
		}
	}

	int i = firstW(s);
	while(--i >= 0 && k) {
		s[i] = 'W';
		k--;
	}

	i = lastW(s);
	while(k-- > 0 && ++i < n) {
		s[i] = 'W';
	}
	debug(s);
	cout << calculate(s) << "\n";
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