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
int university[mxN];

void solve() {
	cin >> n;

	vector<vector<int>> uv(n + 1);
	vector<int> ans(n + 1);

	for(int i = 1; i <= n; i++) {
		cin >> university[i];
	}

	for(int i = 1; i <= n; i++) {
		int s;
		cin >> s;
		uv[university[i]].push_back(s);
	}

	for(int i = 1; i <= n; i++) {
		sort(uv[i].rbegin(), uv[i].rend());

		for(int j = 1; j < uv[i].size(); j++) {
			uv[i][j] += uv[i][j - 1];
		}

		debug(uv[i]);

		int n1 = uv[i].size();

		bool done[n1 + 1] = {};

		for(int j = n1 - 1; j >= 0; j--) {

			int currNo = j + 1;

			for(int f = 1; f * f <= currNo; f++) {
				if(currNo % f) {
					continue;
				}

				if(!done[f]) {
					ans[f] += uv[i][j];
					done[f] = true;
				}

				int f1 = currNo / f;

				if(!done[f1]) {
					ans[f1] += uv[i][j];
					done[f1] = true;
				}
			}

		}
	}

	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
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