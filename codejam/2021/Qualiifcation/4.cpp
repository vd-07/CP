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

#define int double

const int N = 1e5 + 10;

long long n, m;
long long p;

static double d2r(double d) {
  return (d / 180.0) * ((double) M_PI);
}

void solve() {
	cin >> n >> m;

	vector<int> a(n), b(m);

	int s1 = 0;
	for(long long i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = sin(d2r(a[i]));

		s1 += a[i];
	}	

	int s2 = 0;

	for(long long i = 0; i < m; i++) {
		cin >> b[i];
		b[i] = sin(d2r(b[i]));
		s2 += b[i];
	}

	cin >> p;

	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());

	if(s1 < s2) {
		swap(s1, s2);
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		swap(a, b);
	}

	long long i = n - 1, j = m - 1;

	int cost = 0;

	 while((i >= 0 || j >= 0) && s1 > s2 && cost < p) {
        cost ++;
        
        if(j < 0) {
            // cost1 = a[i];
            s1 -= a[i];
            i --;
            continue;
        }
        

        if(i < 0) {
            // cost2 = 1 - b[j];
            s2 += 1 - b[j];
            j--;
            continue;
        }
    		int cost2 = 1 - b[j];	
    		int cost1 = a[i];
        if(cost1 > cost2) {
            s1 -= a[i];
            i --;
        } else {
            s2 += 1 - b[j];
            j --;
        }
    }
    if(s1 <= s2) {
        cout << cost;
    } else {
        cout << "NO";
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
	long long t = 1;
    	// cin >> t;
    	for(int i = 1; i <= t; i++) {
        // cout << "Case #"<< i << ": ";
        solve();
    	}

	return 0;
}