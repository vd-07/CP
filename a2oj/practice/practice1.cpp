#include <iostream>
using namespace std;
#define mod 1000000007

int32_t main() {
	int n, m;
	cin >> n >> m;
	cout << (min(n, m) + 1) << "\n";
	for(int i = 0; i <= min(n, m); i++)
		cout << i << " " << min(n, m) - i <<  "\n";
	return 0;
}

