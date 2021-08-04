//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define uint unsigned long long int
#define sz(a) (int)((a).size())
//read
#define READ(a) int a; cin>>a
#define READ2(a,b) int a,b; cin>>a>>b
#define READ3(a,b,c) int a,b,c; cin>>a>>b>>c
#define READ4(a, b, c, d) int a, b, c, d; cin >> a >> b >> c >> d
#define READC(c) char c; cin>>c
#define READA(a,n) int a[n]; for(int i = 0; i < n; i++) cin>>a[i]
#define READS(s) string s; cin>>s
//debug
#define d1(a) cerr << #a << " " << a << endl;
#define d2(a, b) cerr << #a << " " << a << " " << #b << " " << b << endl;
#define d3(a, b, c) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << endl;
#define d4(a, b, c, d) cerr << #a << " " << a << " " << #b << " " << b << " " << #c << " " << c << " " << #d << " " << d << endl;
//for loop
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
//general
#define test int t; cin>>t; while(t--)
#define mod 1000000007
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int,int> 
#define int128 __int128
#define ff first
#define ss second

// //from https://cp-algorithms.com/algebra/linear-diophantine-equation.html
// int gcd(int a, int b, int& x, int& y) {
//     if (b == 0) {
//         x = 1;
//         y = 0;
//         return a;
//     }
//     int x1, y1;
//     int d = gcd(b, a % b, x1, y1);
//     x = y1;
//     y = x1 - y1 * (a / b);
//     return d;
// }

// bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
//     g = gcd(abs(a), abs(b), x0, y0);
//     if (c % g) {
//         return false;
//     }

//     x0 *= c / g;
//     y0 *= c / g;
//     if (a < 0) x0 = -x0;
//     if (b < 0) y0 = -y0;
//     return true;
// }

// void shift_solution(int & x, int & y, int a, int b, int cnt) {
//     x += cnt * b;
//     y -= cnt * a;
// }

// int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
//     int x, y, g;
//     if (!find_any_solution(a, b, c, x, y, g))
//         return 0;
//     a /= g;
//     b /= g;

//     int sign_a = a > 0 ? +1 : -1;
//     int sign_b = b > 0 ? +1 : -1;

//     shift_solution(x, y, a, b, (minx - x) / b);
//     if (x < minx)
//         shift_solution(x, y, a, b, sign_b);
//     if (x > maxx)
//         return 0;
//     int lx1 = x;

//     shift_solution(x, y, a, b, (maxx - x) / b);
//     if (x > maxx)
//         shift_solution(x, y, a, b, -sign_b);
//     int rx1 = x;

//     shift_solution(x, y, a, b, -(miny - y) / a);
//     if (y < miny)
//         shift_solution(x, y, a, b, -sign_a);
//     if (y > maxy)
//         return 0;
//     int lx2 = x;

//     shift_solution(x, y, a, b, -(maxy - y) / a);
//     if (y > maxy)
//         shift_solution(x, y, a, b, sign_a);
//     int rx2 = x;

//     if (lx2 > rx2)
//         swap(lx2, rx2);
//     int lx = max(lx1, lx2);
//     int rx = min(rx1, rx2);

//     if (lx > rx)
//         return 0;
//     return (rx - lx) / abs(b) + 1;
// }

void solve() {
	READ3(l, r, m);
    int range = r - l;
    // check for l == 1
    int a = -1;
    while(range >= 0) {
        int v = m - range;
        for(int i = 1; i * i <= v; i++) {
            if(v % i) continue;
            if(i >=l  && i <= r) {
                a = i;
                break;
            }
            if(v / i >= l && v / i <= r) {
                a = v / i;
                break;
            }
        }
        if(a != -1) {
            cout << a << " " << l + range << ' ' << l << "\n";
            return;
        }
        range--;
    }
    range = r - l;
    while(range >= 0) {
        int v = m + range;
        for(int i = 1; i * i <= v; i++) {
            if(v % i) continue;
            if(i >=l  && i <= r) {
                a = i;
                break;
            }
            if(v / i >= l && v / i <= r) {
                a = v / i;
                break;
            }
        }
        if(a != -1) {
            cout << a << " " << l << ' ' << l + range << "\n";
            return;
        }
        range--;
    }
}

int32_t main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("output.txt", "w", stdout);
	#endif
    fastIO

	test solve();



	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    return 0;
}