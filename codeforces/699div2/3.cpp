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
int n, m;

void solve() {
	cin >> n >> m;

	vector<int> a(n), b(n), c(m);

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> demand(n + 1, 0), last(n + 1, -1);

	map<int, vector<int>> idx; 

	vector<bool> doesExist(n + 1, false);

	for(int i = 0; i < n; i++) {
		cin >> b[i];

		doesExist[b[i]] = true;

		last[b[i]] = i;

		if(a[i] != b[i]) {
			demand[b[i]] ++;
			idx[b[i]].push_back(i);	
		}
	}

	debug(idx);

	bool ok = true;

	vector<int> ans(m);

	vector<int> nonExist;

	int correct = -1;

	for(int i = 0; i < m; i++) {
		cin >> c[i];

		if(ok == false) {
			continue;
		}

		if(doesExist[c[i]] == false) {
			nonExist.push_back(i);
			continue;
		}

		correct = i;

		if(idx[c[i]].empty()) {
			// no changes req but present
			// should be directed to consume nonExists
			ans[i] = last[c[i]];
			continue;
		}

		ans[i] = idx[c[i]].back();

		a[ans[i]] = b[ans[i]];

		if(demand[c[i]]) {
			demand[c[i]] --;
			idx[c[i]].pop_back();
		}
		
		// any correct c[i] can be used to fuck all non Existing c[i]s
		// can be used to remove non existing c[i]
		// only if their index is lesser than extra

	}

	if(!nonExist.empty()) {
		if(nonExist.back() > correct) {
			ok = false;
		} else {
			for(int i : nonExist) {
				ans[i] = ans[correct];
			}
		}
	}

	for(int i = 0; i < n; i++) {
		if(a[i] != b[i]) {
			ok = false;
			break;
		}
	}

	if(ok == false) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for(int i : ans) {
			cout << i + 1 << " ";
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
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}