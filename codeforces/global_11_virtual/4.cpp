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

const int mxN = 53;

int n, k;
vector<int> a(mxN);

vector<int> findDset() {
	vector<int> d;

	// scheme
	// xx y(inc) xxx-yyy xxx
      // xxx xxx-yyy-y xx
      // or
      // xx xxx yyy xxx-y xxxx
	// xxxx xxx-y yyy xxxx xx  
	// two steps
	// can only do the first part

	// g1 before has greater values
	// g2 after, has smaller values

	int mark = -1;

	bool first = false;
	bool doall = false;

	for(int i = 0; i < n; i++) {
		debug(mark);
		if(doall) {
			d.back()++;
			continue;
		}

		if(mark == a[i]) {
			if(first == false) {
				d.push_back(0);
			}

			d.back()++;

			if(i != n - 1) {
				d.push_back(0);
			}
			
			doall = true;
			continue;
		}

		if(mark != -1) {
			if(a[i] == a[i - 1] + 1 || first) {
				d.back()++;
			}
			else {
				first = true;
				d.push_back(1);
			}
			continue;
		}

		if(mark == -1 && a[i] != i + 1) {
			d.push_back(1);
			mark = a[i] - 1;
		}
		else {
			if(d.empty()) {
				d.push_back(0);
			}
			d.back()++;
		}

	}

	debug(d);

	return d;
}

void reverse(vector<int> d) {
	vector<vector<int>> temp;

	int i = 0;
	for(int len : d) {

		vector<int> te;

		while(len--) {
			te.push_back(a[i++]);
		}

		temp.push_back(te);
	}

	reverse(temp.begin(), temp.end());

	i = 0;

	for(vector<int> te : temp) {
		for(int tem : te) {
			a[i++] = tem;
		}
	}
}

void solve() {
	cin >> n;
	a = vector<int> (n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<vector<int>> answer;

	int cot = 0;

	while(!is_sorted(a.begin(), a.end())) {
		cot++;
		assert(cot <= n);
		// find D
		vector<int> d = findDset();
		// reverse the array

	
		reverse(d);
		// store answer

		debug(a);

		answer.push_back(d);
	}

	cout << answer.size() << "\n";

	for(vector<int> ans : answer) {
		cout << ans.size() << " ";
		for(int aa : ans) {
			cout << aa << " ";
		}
		cout << "\n";
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