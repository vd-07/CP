#include<iostream>
#include<cstring>

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
const int N = 100000;
int pf[N + 1];
int lcm[N + 1];

void primeF() {
	memset(pf, 0, sizeof(pf));
	pf[1] = 1;
// 	for(int  i = 2; i <= N; i++) pf[i] = i;
	for(int i  = 2; i <= N; i++) {
		if(!pf[i]) {
// 			pf[i] = i;
			for(int j = i; j <= N; j += i)
				pf[j] = i;
		}
	}
}

void calclcm(int num) {
	while(num > 1) {
		int f = pf[num], count = 0;
		while(num % f == 0) {
			num /= f;
			count++;
		}
		lcm[f] = max(lcm[f], count);
	}
	
}

void solve() {
	memset(lcm, 0, sizeof(lcm));
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		calclcm(a[i]);
	}
	int ans = 1, by = 1;
	for(int i = 2; i <= m; i++) {
		int num = i, t = 1;
		while(num > 1) {
			int count = 0, d = pf[num];
			while(num % d == 0) {
				count++;
				num /= d;
			}
			if(lcm[d] < count) 
				t *= (count - lcm[d]) * d;
		}
		if(t > by) {
			ans = i;
			by  = t;
		}
	}
	cout << ans << "\n";
}

int main() {
	fastIO
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif
	primeF();
	int t;
	cin >> t;
	while(t--) solve();
// 	for(int i = 1; i <= N; i++) {
// 	    if(pf[i] == 0)
// 		cout<<i<<" "<<pf[i]<<" ";
// 	}
}