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

const int mx = 200005;

int n, m, k;
int dsu[mx], siz[mx];
 
int findSet(int x)
{
    if(dsu[x] != x)
        dsu[x] = findSet(dsu[x]);
    return dsu[x];
}
 
void mergeSet(int u, int v)
{
    u = findSet(u);
    v = findSet(v);
    if(u == v)
        return;
    if(siz[u] < siz[v])
        swap(u, v);
    dsu[v] = u;
    siz[u] += siz[v];
}
 
void initialise(int n)
{
    for(int i = 0; i <= n; i++)
    {
        dsu[i] = i;
        siz[i] = 1;
    }
}


void solve() {

	cin >> n >> m >> k;

	initialise(n);

	vector<array<int, 3>> pq[2];

	for(int i = 0; i < m; i++) {
		int u, v, s;

		cin >> u >> v >> s;

		if(s > k) {
			pq[1].push_back({s, u, v});	
		} else {
			pq[0].push_back({s, u, v});
		}
		
	}

	sort(pq[0].rbegin(), pq[0].rend());
	sort(pq[1].begin(), pq[1].end());

	int added = 0, ans = 0;

	// try to form using only lows
	for(array<int, 3> v : pq[0]) {
		if(findSet(v[1]) != findSet(v[2])) {
			added++;
		}
		mergeSet(v[1], v[2]);
	}

	if(added == n - 1) {
		ans = k - pq[0][0][0];

		if(pq[1].size()) {
			ans = min(ans, pq[1][0][0] - k);
		}
	} else {
		for(array<int, 3> v : pq[1]) {
			// connect them with lowest speed
			debug(findSet(v[1]), findSet(v[2]));

			if(findSet(v[1]) != findSet(v[2])) {
				ans += v[0] - k;
			}

			mergeSet(v[1], v[2]);
		}
	}
	
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

	// test cases
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}