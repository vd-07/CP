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
int a[mxN];

void solve() {
	cin >> n;

	map<int, int> countElements, countFrequency;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		countElements[a[i]] ++;
	}

	vector<pair<int, int>> freq;

	for(pair<int, int> p : countElements) {
		countFrequency[p.second] ++;
	}

	int ans = n;

	for(pair<int, int> p : countFrequency) {
		// {freq, freqfreq}
		freq.push_back({p.first, p.second});
	}

	sort(freq.begin(), freq.end());

	int m = freq.size();

	int removed = 0;

	// int suff[m] = {};

	// suff[m - 1] = 0;

	// for(int i = m - 2; i >= 0; i--) {
	// 	// level to freq.first

	// 	suff[i] = freq[i + 1].first - freq[i].first;

	// 	suff[i] *= freq[i + 1].second;


	// }

	int biggerElements = 0;
	for(int i = m - 1; i >= 0; i--) {
		// lower freq elements needs to be removed completely
		// higher freq are to be leveled to freq.first

		int lowerFreq = n - ((freq[i].first * freq[i].second) + biggerElements);

		debug(lowerFreq, freq[i], removed, biggerElements);

		ans = min(ans, lowerFreq + removed);

		if(i != 0) {
			// till here all bigger elements are equal 
			// their count is 
			removed += (freq[i].first - freq[i - 1].first) * (freq[i].second + removed);	
		}

		biggerElements += freq[i].first * freq[i].second;
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