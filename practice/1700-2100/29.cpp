// https://codeforces.com/problemset/problem/1554/C
//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;

#define int long long

const int mxN = 3e5 + 1;

int n, m;

int count(int no) {
	int c = 0;
	while(no) {
		++ c;
		no /= 2;
	}
	return c;
}

string binary(int no) {
	string ans = "";

	while(no) {
		ans += char((no % 2) + '0');
		no /= 2;
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int decimal(string no) {
	int ans = 0;

	for(char c: no) {
		ans = 2 * ans + (int)(c - '0');
	}

	return ans;
}

int solve(int n, int m) {
	// return (n ^ m) + 1;
	// int x = max(m - n + 1, 0ll);
	// if(count(x) == count(n)) {
	// 	x = pow(2, count(x));
	// }

	// return x;
		
	// cout << binary(n) << endl;
	// cout << binary(m) << endl;
	// cerr << binary(640) << endl;

	// return -1;
	++ m;
	
	string a = binary(n), b = binary(m);

	while(a.size() < b.size()) {
		a = '0' + a;
	}
	while(b.size() < a.size()) {
		b = '0' + b;
	}

	string ans = "";

	for(int i = 0; i < (int)a.size(); ++ i) {
		if(a[i] == '0') {
			ans += b[i];
		} else if(b[i] == '1') {
			ans += '0';
		} else {
			break;
		}
	}

	while(ans.size() < a.size()) {
		ans += '0';
	}

	int x = decimal(ans);

	// if((n ^ x) == m) {
	// 	bool ok = true;
	// 	// cerr << x << endl;
	// 	cerr << ans << endl;
	// 	cerr << a << endl;
	// 	for(int i = (int)a.size() - 1; i >= 0; -- i) {
	// 		if(a[i] == '0' && ans[i] == '0') {
	// 			ans[i] = '1';
	// 			ok = false;
	// 			break;
	// 		} else {
	// 			ans[i] = '0';
	// 		}
	// 	}

	// 	// cerr << ans;

	// 	if(ok) {
	// 		x = pow(2, count(x));
	// 	} else {
	// 		x = decimal(ans);
	// 	}
	// }

	return x;
}

int bruteForce(int n, int m) {
	vector<int> xors;
	for(int i = 0; i <= m; ++ i) {
		xors.push_back(i ^ n);
		// cerr << i << " : " << (i ^ n) << "\n";
	}

	sort(xors.begin(), xors.end());

	int mex = 0;

	for(int i: xors) {
		// cerr << i << endl;
		if(i == mex) {
			++ mex;
		}
	}

	return mex;
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
	while(t--) {
		// n = random() % 10 + 1, m = random() % 10 + 1;
		// int ans1 = solve(n, m);
		// int ans2 = bruteForce(n, m);

		// cerr << n << " " << m << endl;
		// cerr << ans1 << " " << ans2 << endl;

		// if(ans1 != ans2) {
		// 	cerr << "Error\n";
		// 	cerr << n << " " << m << endl;
		// 	cerr << "Your answer: " << ans1 << endl;
		// 	cerr << "Correct answer: " << ans2;
		// 	break;
		// }
		cin >> n >> m;
		cout << solve(n, m) << "\n";
	}

	#ifdef CODINGINVEINS
    	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    	#endif
    	
	return 0;
}