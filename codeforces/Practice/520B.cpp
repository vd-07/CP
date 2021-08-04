#include <iostream>
#include <cstring>
#define int long long int 
using namespace std;

int n, m;
int visited[10001]; 
int dfs(int num, int count = 0) {
	if(num >= 2 * m || num <= n / 2) 
		return -1;
	if(num == m) {
		return count;
	}
	if(visited[num] <= count && visited[num] != -1)
		return -1;
	visited[num] = count;
	int v1 = dfs(num * 2, count + 1);
	int v2 = dfs(num - 1, count + 1);
//	if(v1 != -1 || v2 != -1)
//		cout<< v1<<" "<<v2<<endl;
	return (v1 == -1 || v2 == -1) ? max(v1, v2) : min(v1, v2);
}
int32_t main() {
	memset(visited, -1ll, sizeof(visited));
	cin >> n >> m;
	int res = dfs(n);
	if(n > m)
	res = n - m;
	cout << res;
	return 0;
}
