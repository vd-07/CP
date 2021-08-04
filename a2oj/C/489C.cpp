#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, s;
	cin >> m >> s;
	vector<int> mx(m), mi(m);
	int l, s1 = s;
	for(int i = m - 1; i >= 1; i--) {
		l = s1 - i * 9;
		mx[i] = min(s, 9);
		mi[i] = max(l, i == m - 1? 1 : 0);
		s1 -= mi[i];
		s -= mx[i];
		if(s < 0 || s1 < 0) {
			cout << -1 << " " << -1;
			return 0;
		}
	}
	if(s1 > 9 || s > 9) {
		cout << -1 << " " << -1;
		return 0;
	}
	mi[0] = s1;
	mx[0] = s;
	for(int i = m - 1; i >= 0; i--)
	cout << mi[i];
	cout << " ";
	for(int i = m - 1; i >= 0; i--)
	cout << mx[i];
	return 0;
}	
