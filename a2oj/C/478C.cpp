#include <iostream>
using namespace std;
#define int long long int
int32_t main() {
	int r, g, b;
	cin >> r >> g >> b;
	if(g < b) swap(g, b);
	if(r < g) swap(r, g);
	if(g < b) swap(g, b);
	int ans = 0;
	ans = min((r + b + g) / 3, b + g);
	cout << ans;
	return 0;
}
