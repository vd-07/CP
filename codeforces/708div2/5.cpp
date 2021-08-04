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

const int N = 1e7 + 10;

int n, kk;
int prime[N] = {}, k[N] = {};
vector<int> next;

void sieve() { 
    	for(int i = 1; i < N; i++) {	 
    		k[i] = i; 
    	}
       
    	for(int i = 2; i < N; i++) { 
  
      
        	if(prime[i] == 0) 
            	for (int j = i; j < N; j += i) { 
  
                
                	prime[j] = 1; 
  
                	while (k[j] % (i * i) == 0) {
                    	k[j] /= (i * i); 
                	}
            } 
    	} 
} 

#define f first
#define l last
void optimize() {
	while(kk > 0) {
		vector<vector<int>> segs;

		for(int i = 0; i < n; i++) {
			int last = next[i] - 1;
			// i can go only till here
			vector<int> curr;
			curr.push_back(i);
			for(int j = i + 1; j <= last; j++) {
				last = min(last, next[j] - 1);
				curr.push_back(j);
			}

			segs.push_back(curr);

			// cost

			i = last;
		}	

		if(segs.size() == 1) {
			break;
		}

		vector<vector<pair<int, int>>> probs(segs.size());

		int id = 0, cost = n;

		for(int i = 0; i + 1 < segs.size(); i++) {
			int e2 = segs[i + 1].back();
			int e1 = segs[i].back();
			vector<pair<int, int>> curr;
			for(int e : segs[i]) {
				if(next[e] > e1 && next[e] <= e2) {
					curr.push_back({e, next[e]});
				}
			}
			probs[i] = curr;

			if(cost > curr.size()) {
				cost = curr.size();
				id = i;
			}
		}

		
	}

}

void solve() {
	cin >> n >> kk;

	int a[n];
	next = vector<int> (n + 1);
	map<int, int> id;

	for(int i = 0; i < n; i++) {
		cin >> a[i];	
	}

	for(int i = n - 1; i >= 0; i--) {
		int kval = k[a[i]];
		if(id.find(kval) == id.end()) {
			next[i] = n;
		} else {
			next[i] = id[kval];
		}
		id[kval] = i;
	}

	int ans = 0;


	

	cout << ans << "\n";
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