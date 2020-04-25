#include <iostream>
using namespace std;
#define mod 100000000
int n1, n2, k1, k2;
int dp[101][101][11][11];

int dadada(int c1 = 0, int c2 = 0, int d1 = 0, int d2 = 0) {
	// cout << c1 << " " << c2 << " " << d1 << " " << d2 << endl;
	if(d1 == n1 && c2 == k2 && d2 != n2)
		return dp[d1][d2][c1][c2] = 0;
	if(d2 == n2 && c1 == k1 && d1 != n1)
		return dp[d1][d2][c1][c2] = 0;
	if(dp[d1][d2][c1][c2] != -1)
		return dp[d1][d2][c1][c2];
	if((d1 == n1 && d2 == n2 - 1) || (d1 == n1 - 1 && d2 == n2))
		return dp[d1][d2][c1][c2] = 1;
	int curr = 0, murr = 0;
	if(c1 == k1 || d1 == n1)
		curr = dadada(0, c2 + 1, d1, d2 + 1);
	else if(c2 == k2 || d2 == n2)
		curr = dadada(c1 + 1, 0, d1 + 1, d2);
	else	{
		curr = dadada(c1 + 1, 0, d1 + 1, d2);
		murr = dadada(0, c2 + 1, d1, d2 + 1);
	}
	return dp[d1][d2][c1][c2] = (curr + murr) % mod;
}

int main() {
	cin >> n1 >> n2 >> k1 >> k2;
	for(int i = 0; i <= 100; i++)
		for(int j = 0; j <= 100; j++)
		       for(int k = 0; k <= 10; k++)
		       		for(int l = 0; l <= 10; l++)
					dp[i][j][k][l] = -1;	       
	int ans = dadada();
	
	cout << ans;
	return 0;
}
