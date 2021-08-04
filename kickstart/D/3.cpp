//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m;
int skills[mxN];

void solve() {
	cin >> n >> m;

	set<pair<int, int>> s;

	for(int i = 0; i < n; ++ i) {
		int a, b;
		cin >> a >> b;

		s.insert({a, b});
	}

	for(int i = 0; i < m; ++ i) {
		int si;
		cin >> si;

		auto ltr = s.upper_bound({si, si});
		auto utr = ltr;

		if(ltr != s.begin()) {
			-- ltr;
		}



		// cout << (ltr->first) << endl;

		if(utr == s.end()) {
			// cout << *ltr << " ";

			int l = ltr->first;
			int r = ltr->second;

			s.erase(ltr);

			if(l <= si && si <= r) {
				cout << si << " ";

				if(l <= si - 1) {
					s.insert({l, si - 1});
				}

				if(si + 1 <= r) {
					s.insert({si + 1, r});
				}
			} else {
				// take r or l?
				if(abs(l - si) <= abs(r - si)) {
					if(l + 1 <= r) s.insert({l + 1, r});
					cout << l << " ";
				} else {
					if(l <= r - 1) s.insert({l, r - 1});
					cout << r << " ";
				}
			}
			
		} else {
			
			int l1 = ltr->first;
			int r1 = ltr->second;
			int l2 = utr->first;
			int r2 = utr->second;

			if(si == l2) {
				cout << l2 << " ";
				s.erase(utr);
				if(l2 + 1 <= r2) s.insert({l2 + 1, r2});
			} else {
				if(l1 <= si && si <= r1) {
					s.erase(ltr);
					cout << si << " ";

					if(l1 <= si - 1) {
						s.insert({l1, si - 1});
					}

					if(si + 1 <= r1) {
						s.insert({si + 1, r1});
					}
				} else {
					// take r or l?
					if(abs(r1 - si) <= abs(l2 - si)) {
						s.erase(ltr);
						if(l1 <= r1 - 1) s.insert({l1, r1 - 1});
						cout << r1 << " ";
					} else {
						cout << l2 << " ";
						s.erase(utr);
						if(l2 + 1 <= r2) s.insert({l2 + 1, r2});
					}
				}
			}

		}
	}

	cout << "\n";
}

int32_t main() {
	#ifdef CODINGINVEINS
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
	for(int i = 1; i <= t; i++) {
        cout << "Case #"<< i << ": ";
        solve();
    	}
	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif

	return 0;
}