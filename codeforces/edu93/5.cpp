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
	#define ll long long
	#define ff(i,a,b) for( ll i=a;i<b;i++)

bool solve2(int n, vector<int> lily) {
	ll f=1;
	std::vector<ll>::iterator it,lower;
	ll k= lily.size();
	ff(i,0,lily.size()-1)
	{
		ll q=lily.at(i)+lily.at(i+1);
		lower = lower_bound (lily.begin(), lily.end(),q); 
		if(lower-lily.begin()<k)
		{
			return true;
			f=0;
			break;
		}
	}
	return false;
}

bool solve1(int n, vector<int> a) {
	if(a[0] + a[1] <= a[n - 1]) {
		return true;
	}
	else {
		return false;
	}
}

int32_t main() {

	// for fast i/o
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	while(1) {
		int n = rand() % (4998) + 3;
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			a[i] = rand() % (1000000000) + 1;
		}
		sort(a.begin(), a.end());
		if(solve1(n, a) != solve2(n, a)) {
			cout << n << "\n";
			for(int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			return 0;
		}
		else {
			cout << n << "  ok\n";
		}
	}
	

	return 0;
}