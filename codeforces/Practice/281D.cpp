#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> s;
	int ele;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> ele;
		if(s.empty()) {
			s.push(ele);
		       	continue;
		}
		while(!s.empty() && ele > s.top()) {
			ans = max(ans, ele ^ s.top());
			s.pop();
		}	
		ans = max(ans, ele ^ s.top());
		s.push(ele);
	}
	cout << ans;
	return 0;
}
