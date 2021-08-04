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

int n, m;

void startJourney(int x, int y, int z, int m) {

	// print x, y, z, x, y, z m + 1 times
	cout << "YES\n";
	for(int i = 0; i <= m; i++) {
		switch(i % 3) {
			case 0 : cout << x << " "; break;
			case 1 : cout << y << " "; break;
			case 2 : cout << z << " "; break;
		}
	}

}

void solve() {
	cin >> n >> m;

	vector<vector<int>> adjacencyMatrix(n, vector<int> (n));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {

			char weight;

			cin >> weight;

			switch(weight) {
				case 'a' : adjacencyMatrix[i][j] = 0; break;
				case 'b' : adjacencyMatrix[i][j] = 1; break;
				default : adjacencyMatrix[i][j] = 2;
			}
		}
	}

	// if length is odd
	if(m & 1) {
		cout << "YES\n";

		m++;

		while(m--) {
			cout << ((m & 1) ? 1 : 2) << " ";
		}
		return;
	} 

	// now length is even

	// is length is 2, need same edges's weight

	// find if a cycle has same weight

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(adjacencyMatrix[i][j] == adjacencyMatrix[j][i]) {
				// got my answer here
				cout << "YES\n";

				m++;

				while(m--) {
					cout << ((m & 1) ? i + 1 : j + 1) << " ";
				}
				return;
			}
		}
	}

	if(n <= 2) {
		cout << "NO\n";
		return;
	}

	// the only case left is n > 2 and length is even and no two vertices have same
	// outgoing as well as incoming edge weight

	// take three random nodes x, y, z
	// let weight x -> y be w1 y -> z be w2 and z -> x be w3
	// it is guarantted that atleast one of w1, w2, w3 will be equal to the other (pigeon hole principle)

	int x = 0, y = 1, z = 2;

	int w1 = adjacencyMatrix[x][y], w2 = adjacencyMatrix[y][z], w3 = adjacencyMatrix[z][x];

	// let w2 and w3 be equal

	if(w1 == w2) {
		x = 3;
		y = 1;
		z = 2;
	} else if(w1 == w3) {
		x = 2;
		y = 3;
		z = 1;
	} else {
		x++;
		y++;
		z++;
	}

	if((m - 2) % 6 == 0) {
		// 2, 8, 14, 20 ......
		// aaba|abaa

		startJourney(y, z, x, m);

	} else if((m - 4) % 6 == 0) {
		// 4, 10, 16, 22
		// baaba|abaab

		startJourney(x, y, z, m);
	} else {
		// 6, 12, 18
		// aba|aba

		startJourney(z, x, y, m);
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

	
	int t = 1;

	cin >> t;

	while(t--) {
		solve();
		cout << "\n";
	}


	return 0;
}