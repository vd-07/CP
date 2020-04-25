#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if(n > m + 1 || (n + 1) * 2 < m) {
		cout << -1;
		return 0;
	}
	vector<int> ans;
	bool d1 = false, d2 = false;
	while(n !=0 || m != 0) {
		if(m > n && d2 == false && m >= 2) {
			ans.push_back(1);
			ans.push_back(1);
			d2 = true;
			d1 = false;
			m -= 2;
		}
		else if(d1 == false) {
			ans.push_back(0);
			d1 = true;
			d2 = false;
			n--;
		}
		else if(d2 == false){
			ans.push_back(1);
			d2 = true;
			d1 = false;
			m--;
		}
		else {
			cout << -1;
			return 0;
		}
	}
	for(auto e:ans) cout <<e;
	return 0;
}
