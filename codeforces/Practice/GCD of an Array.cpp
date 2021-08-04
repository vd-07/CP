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

const int N = 3e5 + 1;
const int mod = 1e9 + 7;

int spf[N];

int n, q;
map<int, map<int, int>> prime, arr;

void sieve() {
	for(int i = 1; i < N; i++) {
		spf[i] = i;
	}

	for(int i = 2; i * i < N; i++) {
		if(spf[i] == i) {
			for(int j = i * i; j < N; j += i) {
				spf[j] = i;
			}
		}
	}
}

int power(int base, int expo) {
	int res = 1;

	while(expo) {
		if(expo & 1) {
			res = (res * base) % mod;
		}
		base = (base * base) % mod;
		expo /= 2;
	}

	return res;
}

void solve() {
	cin >> n >> q;

	int gcd = 0;

	for(int i = 1; i <= n; i++) {
		int e; 
		cin >> e;

		gcd = __gcd(gcd, e);

		while(e > 1) {
			int currPrime = spf[e];

			int cnt = 0;

			while(e % currPrime == 0) {
				cnt ++;
				e /= currPrime;	
			}

			prime[currPrime][cnt] ++;
			arr[i][currPrime] = cnt;
		}
	}

	// debug(prime);

	for(auto &p1 : prime) {
		int cnt = n;
		for(auto &p2 : p1.second) {
			cnt -= p2.second;
		}
		prime[p1.first][0] = cnt;
	}

	while(q--) {
		int i, x;
		cin >> i >> x;

		while(x > 1) {
			int currPrime = spf[x];

			int cnt = 0;

			while(x % currPrime == 0) {
				x /= currPrime;
				cnt ++;
			}

			int currPower = arr[i][currPrime];
			int newPower = currPower + cnt;

			if(prime.find(currPrime) == prime.end()) {
				prime[currPrime][0] = n;
			}
			
			int oldPower = prime[currPrime].begin()->first;

			debug(currPrime, currPower, newPower);

			prime[currPrime][currPower] --;
			prime[currPrime][newPower] ++;
			arr[i][currPrime] += cnt;

			if(prime[currPrime][currPower] == 0) {
				prime[currPrime].erase(currPower);
			}

			int nearestPower = prime[currPrime].begin()->first;
			// new gcd will slip to the nearest power of the prime
			// as all the upper primes >= nearest power prime
			// debug(nearestPower, currPower);
			gcd *= power(currPrime, (nearestPower - oldPower));
			gcd %= mod;
		}

		cout << gcd << "\n";
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
	sieve();
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