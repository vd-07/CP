#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	// int neg = 0, pos = 0;
	stack<int> s;
	for(int i = 0; i < n; i++) {
		// if(a[i] == 1) pos++;
		// else neg++;
		// if(neg > pos) {
		// 	cout << "NO";
		// 	return 0;
		// }
		if(a[i] == 1) s.push(1);
		if(a[i] == -1) {
			if(s.empty()) {
				cout << "NO";
				return 0;
			}
			s.pop();
		}
	}
	if(s.empty())
		cout << "YES";
	else
		cout << "NO";
	return 0;
}