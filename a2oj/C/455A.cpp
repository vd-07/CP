#include <iostream>
#include <unordered_set>
using namespace std;
int a[100001];
int n;
long long int dp[100001];
long long int solve(int ptr, unordered_set<int> mark) {
	if(ptr == n + 1) return 0;
	if(dp[ptr] != -1) {
		cout << ptr << " " << dp[ptr] << endl;
		return dp[ptr];
	}
	int v1 = solve(ptr + 1, mark);
	int val = a[ptr];
	//cout << v1 << " " << ptr << "\n";
	if(mark.find(val) != mark.end())
		return v1;
	mark.insert(val + 1), mark.insert(val - 1);
	int v2 = val + solve(ptr + 1, mark);
	//cout << v2 << " " << v2 << " " << ptr  << "\n";
	return dp[ptr] = max(v1, v2);	
}
int main() {
	cin >> n;
	int freq[100001] = {};
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		freq[a[i]]++;
	}
	//unordered_set<int> mark;
	dp[0] = 0;
	dp[1] =	freq[1]; 
	for(int i = 2; i <= 100000; i++) 
	dp[i] = max(dp[i - 2] + 1ll * freq[i] * i, dp[i - 1]);	
	cout << dp[100000]; 
	return 0;
}
