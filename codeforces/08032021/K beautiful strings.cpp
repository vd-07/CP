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

int n, k;
string s;

void solve() {
	cin >> n >> k;
	cin >> s;

	if(n % k) {
		cout << "-1\n";
		return;
	}

	// construct prefix
	vector<vector<int>> cnt(n, vector<int> (26));

	for(int i = 0; i < n; ++ i) {
		++ cnt[i][s[i] - 'a'];

		if(i > 0) {
			for(int j = 0; j < 26; ++ j) {
				cnt[i][j] += cnt[i - 1][j];
			}
		}
	}

	for(int i = n - 1; i >= 0; -- i) {
		int sum = 0;

		for(int j = 0; j < 26; ++ j) {
			int ct = cnt[i][j];
			int extra = (k - (ct % k)) % k;

			sum += extra;
		}

		if(sum == 0 && i == n - 1) {
			cout << s << "\n";
			return;
		}

		sum -= (k - (cnt[i][s[i] - 'a'] % k)) % k;
		cnt[i][s[i] - 'a'] --;
		sum += (k - (cnt[i][s[i] - 'a'] % k)) % k;

		for(int j = s[i] - 'a' + 1; j < 26; j++) {
			// fix s[i] with j
			// sum -= (k - (ct[i][j] % k)) % k;
			int last_sum = sum;
			sum -= (k - (cnt[i][j] % k)) % k;
			cnt[i][j] ++;
			sum += (k - (cnt[i][j] % k)) % k;

			if(sum <= n - i - 1) {
				// done
				for(int p = 0; p < i; p++) {
					cout << s[p];
				}

				cout << char(j + 'a');

				// cnt[i][j] --;

				sum = n - i - 1 - sum;

				while(sum --) {
					cout << 'a';
				}

				// print the rest of the char
				for(int j = 0; j < 26; ++ j) {
					int ct = cnt[i][j];
					int extra = (k - (ct % k)) % k;
					while(extra --) {
						cout << char(j + 'a');
					}
			
				}
				cout << '\n';
				return;
			}

			sum = last_sum;
			cnt[i][j] --;
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