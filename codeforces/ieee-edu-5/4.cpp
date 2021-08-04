//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

class UnionFind {
	private:
	vector<int> p, rank;
	public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0);
		for(int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int  i, int j) {
		if(!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y])
				p[y] = x;
			else {
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}	
	int numDisjointSets() {
		int count = 0;
		for(int  i = 0; i < (int)p.size(); i++) {
			if(p[i] == i)
				count++;
		}
		return count;
	}
	int sizeofSet(int i) {
		int parent = findSet(i);
		int count = 0;
		for(int i = 0; i < (int)p.size(); i++) {
			if(p[i] == parent)
				count++;
		}
		return count;
	}
};

int L, R, q, x, y;
const int N = 1e6 + 10;

UnionFind uf(N);

void construct() {
	vector<bool> isPrime(N, true);
	for(int i = 2; i < N; ++ i) {
		if(isPrime[i]) {
			for(int j = i; j < N; j += i) {
				isPrime[j] = false;
				if(j >= L && j <= R) {
					uf.unionSet(i, j);	
				}
			}
		}
	}
}

void solve() {
	cin >> L >> R;

	cin >> q;
	construct();
	while(q--) {
		cin >> x >> y;
		if(uf.isSameSet(x, y)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

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

	// cin >> t;
	while(t--) {
		// int n = rand() % 10 + 1;
		// int m = rand() % n + 1;
		// int p = rand()

		solve();
	}

	#ifdef CODINGINVEINS
    	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}