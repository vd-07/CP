#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e3 + 10;

int dp[N][N][2][2];

int n, z, x, y;

int solve2(int* a, int* b, int i = 0, int j = 0, bool xx = 0, bool yy = 0) {
	//either i am out of books or i am out of money
	if(i == n || j >= z) {
		return 0;
	}
	//already calculated
	if(dp[i][j][xx][yy] != -1) return dp[i][j][xx][yy];
	int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
	//not considering this book
	v1 = solve2(a,b,i+1,j,xx,yy);

	if((b[i] + j) <= z) {
		if(!xx){
			//considering this book and also using the gauntlet for x
			//increasing the spent money
			//adding to the number of pages
			v2 = solve2(a, b, i + 1, j + b[i], 1, yy) + a[i] * x ;
		}
		if(!yy){
			//considering this book and also using the gauntlet for y
			v3 = solve2(a, b, i + 1, j + b[i], xx, 1) + a[i]*y ;
		}
		//considering this book without using the gauntlet
		v4 = solve2(a, b, i + 1, j + b[i], xx, yy) + a[i] ;
	}
	//returning the maximum of them all
	return	dp[i][j][xx][yy] = max({v1,v2,v3,v4}) ;
}

void solve() {
	memset(dp,-1ll,sizeof(dp)) ;
	cin >> n >> z >> x >> y ;
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++) cin>>a[i];
	for(int i = 0; i < n; i++) cin>>b[i];
	int ans = solve2(a, b);
	cout << ans << '\n';
}

int32_t main(){
	// int t ;
	// cin>>t ;
	// while(t--)
		solve();
	return 0 ;
}