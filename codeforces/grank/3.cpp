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
	#define float double

const int mxN = 3e5 + 1;

int n, l;
float a[mxN];

float t1[mxN], t2[mxN];
float v1[mxN], v2[mxN];

bool check(float t1, float t2) {
	float pres = abs(t1 - t2);
	return pres <= 0.0000001;
}

float calc1(float coor) {
	// starts from 0
	// find the prev coord and the associated time
	int i = lower_bound(a, a + n + 2, coor) - a;

	if(a[i] == coor) {
		return t1[i];
	}

	if(a[i] > coor)
		i--;

	float t = t1[i];

	float dist = coor - a[i];

	t += dist / v1[i];

	return t;
}

float calc2(float coor) {
	// starts from l
	// find coor just greater than coor
	int i = upper_bound(a, a + n + 2, coor) - a;

	if(a[i] == coor) {
		return t2[i];
	}


	float t = t2[i];

	float dist = a[i] - coor;

	t += dist / v2[i];

	return t;
}

bool check1(float n1, float n2) {
	float val = (n1 - n2) * 1000000;

	return val >= 0;

}

float binSearch(float lo, float hi) {
	int t = 0;
	int ct = 0;

	while(ct < 1000) {
		float mid = (lo + hi) / 2;

		ct++;
		float t1 = calc1(mid);
		float t2 = calc2(mid);

		debug(t1, t2, mid);
		t = t1;

		if(check(t1, t2)) {
			return t1;
		}

		if(t1 > t2) {
			hi -= mid - lo;
		}
		else {
			lo += hi - mid;
		}
	}

	return t;
}

void build1() {
	t1[0] = 0;
	v1[0] = 1;

	for(int i = 1; i <= n + 1; i++) {
		float dist = a[i] - a[i - 1];

		float t = dist / v1[i - 1];

		t1[i] = t + t1[i - 1];

		v1[i] = v1[i - 1] + 1;
	}
}

void build2() {
	t2[n + 1] = 0;
	v2[n + 1] = 1;

	for(int i = n; i >= 0; i--) {
		float dist = a[i + 1] - a[i];

		float t = dist / v2[i + 1];

		t2[i] = t + t2[i + 1];

		v2[i] = v2[i + 1] + 1;
	}
}

void solve() {
	cin >> n >> l;

	a[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[n + 1] = l;

	// build for car 1
	build1();

	// car 2
	build2();

	float ans = binSearch(0, l);

	cout << fixed << setprecision(12) << ans << "\n";
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