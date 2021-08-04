#include <iostream>
using namespace std;
int n0, n1, n2;
int t;

void solve() {
	cin >> n0 >> n1 >> n2;
	// if(n0) {
	// 	n1--;
	// }
	// if(n0)
	// 	cout << "00";
	// n0--;
	// for(int i = 1; i <= n0; i++)
	// 	cout << 0;
	// if(n2)
	// cout << 11;
	// n2--;
	// bool last = 0;
	// for(int i = 1; i <= n2; i++) cout << 1;
	// if(!(n2 + 1)) {
	// 		if(n1)
	// 		cout << 10;
	// 		n1--;
	// 		for(int i = 1; i <= n1; i++) {
	// 			if(i&1) cout << 1;
	// 			else cout << 0;
	// 			last = i & 1;
	// 		}
	// }
	// else if(--n1 > 0) {
	// 		cout << 0;
	// 		for(int i = 1; i < n1; i++) {
	// 			if(i&1) cout << 1;
	// 			else cout << 0;
	// 			last = i & 1;
	// 		}
				
	// }
	// if(!(n0 + 1))
	// 	if(last) cout << 1;
	// 	else
	// 	cout << 0;
	// // if(n1 && n1 & 1 ^ 1)
	// // 	cout << 1;
	if(n1) {
		for(int i = 1; i <= n2 + 1; i++)
			cout << 1;
		for(int i = 1; i <= n0 + 1; i++)
			cout << 0;
		n1--;
		for(int i = 1; i <= n1; i++) {
			if(i & 1)
				cout << 1;
			else
				cout << 0;
		}
	}	
	else {
		if(n2) {
			for(int i = 1; i <= n2 + 1; i++)
				cout << 1;
		}
		else
			for(int i = 1; i <= n0 + 1; i++)
				cout << 0;
	}
	cout << "\n";
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
    #endif
	cin >> t;
	while(t--) solve();
	return 0;
}