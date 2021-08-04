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
	
const int N = 1e5 + 100;

int p, q;
int pre[N];
vector<array<int, 3>> shop;

int calc1() {
	for(int i = 0; i < p; i++) {
    	pre[i] = shop[i][2] * (shop[i][1] - shop[i][0] + 1);

        if(i > 0) {
            pre[i] += pre[i - 1];
        }
    }

    int ans = 0;

    int j = 0;
    int ct = 0;

    bool ok = true;
    for(int i = 0; i < p; i++) {
        while(j < p && ct < q && ok) {
            ct += shop[j][1] - shop[j][0] + 1;
            j ++;
        }

        if(j == p) {
        	ok = false;
        	j --;
        }

        int curr = pre[j];

        if(i >= 0) {
            curr -= pre[i - 1];
        }

        if(((shop[j][1]) >= (shop[i][0] + q - 1))) {
        	curr -= min((shop[j][1] - (shop[i][0] + q - 1)), shop[j][1] - shop[j][0] + 1) * shop[j][2];	
        }

        ans = max(ans, curr);
        
        ct -= shop[i][1] - shop[i][0] + 1;
    }
    
    return ans;

}

int calc2() {
	reverse(shop.begin(), shop.end());

	for(int i = 0; i < p; i++) {
    	pre[i] = shop[i][2] * (shop[i][1] - shop[i][0] + 1);

        if(i > 0) {
            pre[i] += pre[i - 1];
        }
    }

    int ans = 0;

    int j = 0;
    int ct = 0;

    bool ok = true;
    for(int i = 0; i < p; i++) {
        while(j < p && ct < q && ok) {
            ct += shop[j][1] - shop[j][0] + 1;
            j ++;
        }

        if(j == p) {
        	ok = false;
        	j --;
        }

        int curr = pre[j];

        if(i >= 0) {
            curr -= pre[i - 1];
        }

        if(shop[i][1] - q + 1 > shop[j][0]) {
        	curr -= min(shop[j][1] - shop[j][0], (shop[i][1] - q + 1 - shop[j][0])) * shop[j][2];
        }

        ans = max(ans, curr);
        
        ct -= shop[i][1] - shop[i][0] + 1;
    }
    
    return ans;

}

void solve() {
	cin >> p >> q;

	shop = vector<array<int, 3>> (p);
	

    for(int i = 0; i < p; i++) {
        cin >> shop[i][0] >> shop[i][1] >> shop[i][2];
    }

    sort(shop.begin(), shop.end());

    int ans = calc1();
    // debug(ans);
    ans = max(ans, calc2());
    cout << ans;
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