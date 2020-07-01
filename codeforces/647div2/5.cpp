//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define	mod 1000000007  

int n, p;
int binMul(int base, int exp) {
	int res = 1;
	while(exp > 0) {
		if(exp & 1) {
			res *= base;
			res %= mod;
		}
		exp >>= 1;
		base *= base;
		base %= mod;
	}
	return res;
}
void solve() {
	cin >> n >> p;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	vector<int> sorted;
	int count = 0;
	for(int i = 1; i < n; i++) {
		if(a[i] == a[i - 1]) {
			count++;
		}	
		else {
			if(count & 1)
			sorted.push_back(a[i - 1]);
			count = 1;
		}
	}
	if(sorted.empty()) {
		cout << "0\n";
		return;
	}
	if(count & 1) {
		sorted.push_back(a[n - 1]);
	}
	int s1 = binMul(p, sorted.back());
	int s2 = 0;
	for(int i = 0; i < sorted.size() - 1; i++) {
		s2 += binMul(p, sorted[i]);
		s2 %= mod;
	}
	if(s2 >= s1) 
		s1 += mod;
	int ans = s1 - s2;
	ans %= mod;
	cout << ans << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--)
    	solve();
	return 0;
}
