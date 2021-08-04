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

// bool check(s1, s2) {

// }

bool perform(string &a, char c1, char c2, string &b) {
	int o = 0;
	stack<int> ope;

	for(int i = 0; i < n; i++) {
		if(a[i] == c1) {
			o ++;
			continue;
		}

		if(a[i] == '#') {
			ope.push(i);
			continue;
		}

		// a[i] = is closing
		if(o) {
			continue;
		}
		if(ope.empty()) {
			return false;
		}

		int j = ope.top();
		a[j] = c1, b[j] = c1;
		ope.pop();
		// visited[j] = true;
	}
	return true;
}

bool check(string a) {
	int s = 0;
	for(int i = 0; i < a.size(); i++) {
		if(a[i] == '(') {
			s ++;
		} else if(a[i] == ')') {
			s --;
		} else {
			return true;
		}
		if(s < 0) {
			return true;
		}
	}
	return s != 0;
}

void solve() {
	cin >> n;

	string s;
	cin >> s;

	string a(n, '#'), b(n, '#');

	// as ones are same, so zeros should alternate the choices for a and b
	bool alternate = false;;
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') {
			if(alternate) {
				a[i] = '(';
				b[i] = ')';	
			} else {
				a[i] = ')';
				b[i] = '(';
			}
			alternate ^= 1;
		}
	}

	perform(a, '(', ')', b);
	debug(a, b);
	perform(b, '(', ')', a);	
	debug(a, b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	perform(a, ')', '(', b);
	perform(b, ')', '(', a);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	debug(a, b);

	// fill the rest
	int ct = 0;
	for(char c : a) {
		ct += (c == '#');
	}

	ct /= 2;

	for(int i = 0; i < n; i++) {
		if(a[i] == '#') {
			if(ct) {
				a[i] = '(', b[i] = '(';
				ct --;
			} else {
				a[i] = ')', b[i] = ')';
			}
		}
	}

	if(check(a) || check(b)) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";

	cout << a << "\n" << b << "\n";
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