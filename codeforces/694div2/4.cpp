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

const int mxN = 3e5 + 5;
const int N = 1e6 + 5;

int prime[N] = {};
int k[N] = {};

bool isSquare(int num) {
	int sss = sqrt(num);
	return sss * sss == num;
}

void sieve() {
	for(int i = 1; i < N; i++) {
		k[i] = i;
	}

	for(int i = 2; i < N; i++) {
		if(prime[i] == 0) {
			// a prime
			for(int j = i; j < N; j++) {
				prime[j] = 1;

				while(k[j] % (i * i) == 0) {
					k[j] /= (i * i);
				}
				if(isSquare(k[j])) {
					k[j] = 1;
				}
			}
		}
	}
}

int n, q;

int calc(vector<int> &a) {
	
	map<int, vector<int>> count;

	int a1 = 0;

	for(int i = 0; i < a.size(); i++) {
		debug(a[i], k[a[i]]);
		count[k[a[i]]].push_back(a[i]);
	}

	a.clear();

	for(pair<int, vector<int>> p : count) {
		vector<int> v = p.second;

		int n = v.size();

		if(n % 2 == 0) {
			for(int i = 0; i < n; i++) {
				a.push_back(1);
			}
		} else {
			for(int val : v) {
				a.push_back(val);
			}
		}

		a1 = max(a1, n);
	}

	return a1;
}

void solve() {
	cin >> n;

	vector<int> a(n);

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}


	// can there be a way to have infiinite loop ?
	// 
	// need max no of pairs with perfect square

	int a1 = calc(a);

	// after 1st second
	// all the perfect sqaures will be merged

	// a.clear();

	// for(pair<int, pair<int, int>> p : t2) {
	// 	while(p.second.second--) {
	// 		a.push_back(p.second.first);
	// 	}
	// }

	int a2 = calc(a);

	// for(int i = 0; i < a.size(); i++) {
	// 	if(isSquare(a[i])) {
	// 		a2++;
	// 	}
	// }

	// calc(a);

	cin >> q;
	while(q--) {
		int w;

		cin >> w;
		// debug(w, a1, a2);
		if(w < 1) {
			cout << a1 << "\n";
		} else {
			cout << a2 << "\n";
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

	sieve();

	// test cases
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}