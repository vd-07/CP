#include <iostream>
#define int long long int
using namespace std;

int calc(int x, int n, int m) {
	int res = 0;
	for(int i = 0; i < n; i++)
		res += min((x - 1) / (i + 1) , m);
	return res;
}

int32_t main() {
	int n, m, k;
	cin >> n >> m >> k;
	int l = 1, r = n * m + 1;
	while(l < r) {
		int x = (l + r) / 2;
		if(calc(x, n, m) < k) l = x + 1;
		else r = x;
	}
	cout << l - 1;
	return 0;
}
