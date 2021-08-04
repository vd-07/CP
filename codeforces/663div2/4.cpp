//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

// Macros
#define int long long int
#define uint unsigned long long int
#define sz(a) (int)((a).size())
//read
#define read(a) int a; cin >> a
#define read2(a, b) int a,b; cin>>a>>b
#define read3(a, b, c) int a, b, c; cin >> a >> b >> c
#define read4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d
#define readC(c) char c; cin >> c
#define readA(a, n) int a[n]; for(int i = 0; i < n; i++) cin >> a[i]
#define readS(s) string s; cin >> s
//debug
#define d1(a) cerr << #a << " " << a << endl;
#define d2(a, b) cerr << #a << " " << a << " " << #b << " " << b << endl;
#define d3(a, b, c) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << endl;
#define d4(a, b, c, d) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << " " << #d << " " << d << endl;
//general
#define test int t; cin >> t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define ff first
#define ss second

int power(int, int, int);
int modInverse(int, int);

    
void solve() {
	read2(n, m);
        
    char matrix[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    if(n >= 4 && m >= 4) {
        cout << "-1";
        return;
    }
    if(n == 1 || m == 1) {
        cout << "0";
        return;
    }
    int changed = 0;
    // if(n == 2) {
    int ct1 = 0, ct2 = 0;
    int madeit[n][m] = {};
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            if((madeit[i][j] && madeit[i][j + 1]) || (madeit[i + 1][j] && madeit[i][j]))
                continue;
            ct2 = 0;
            ct2 += (matrix[i][0] == '1');
            ct2 += (matrix[i][1] == '1');
            ct2 += (matrix[i + 1][0] == '1');
            ct2 += (matrix[i + 1][1] == '1');
            if(ct2 % 2 == 0) {
                changed++;
                for(int p = 0; p < 2; p++)
                    for(int q = 0; q < 2; q++)
                        madeit[p + i][q]++;
            }    

        }
    }
    cout << changed;
}

int32_t main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif

	// for fast i/o
    fastIO

    // begin reading test cases
	solve();

    return 0;
}

int power(int x, int y, int p = mod) { 
    int res = 1; 
    x = x % p;  
    while (y > 0){ 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 

int modInverse(int n, int p = mod) { 
    return power(n, p-2, p)%p; 
}