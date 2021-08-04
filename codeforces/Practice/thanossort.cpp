#include <iostream>

using namespace std;

bool issorted(int arr[], int s, int  e) {
	for(int i = s; i < e; i++)
		if(arr[i] > arr[i + 1])
		return false;
	return true;
}
int dfs(int arr[], int s, int e) {
	if(issorted(arr, s, e) || s == e)
	return e - s + 1;
	int mid = (s + e) / 2; 
	int v1 = dfs(arr, s, mid),
		v2 = dfs(arr, mid + 1, e);
	return max(v1, v2);
	
}
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int  i = 0; i < n; i++) cin >> a[i];
	int ans = dfs(a, 0, n - 1);
	cout << ans;		
}
