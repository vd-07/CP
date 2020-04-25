#include <bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
	int n;
	cin >> n;
	int a[n], pre[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	pre[0] = a[0];
	for(int i = 1; i < n; i++) pre[i] = a[i] + pre[i - 1];
	int ans = 0, p, q;
	if(pre[n - 1] % 3 != 0) {
		cout << 0 << "\n";
		return 0;
	}
	p = pre[n - 1] / 3;
	q = 0;
	for(int i = n - 2; i >= 0; i--) {
		if(p == pre[i])
			ans += q;
		if(p * 2 == pre[i])
			q++;
	}
	cout << ans; 
	return 0;
}

