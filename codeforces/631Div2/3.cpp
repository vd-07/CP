#include <iostream>
#define int long long int 
using namespace std;

int max(int n1, int n2) {
	return n1 > n2 ? n1 : n2;
}

int32_t main() {
	int n, m;
	cin >> n >> m;
	int colors[m];
	for(int i = 0; i < m; i++) {
		cin >> colors[i];
		if(colors[i] + i > n) {
			cout << -1;
			return 0;
		}
	}
	int suffix[m + 1] = {};
	for(int i = m - 1; i >= 0; i--) 
		suffix[i] = suffix[i + 1] + colors[i];
	if(suffix[0] < n) {
		cout << -1 << "\n";
		return 0;
	}
	for(int i = 0; i < m; i++)
		cout << max(i + 1, n - suffix[i] + 1) << " ";	
	return 0;
}
