//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;

// Macros
// #define int long long int
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

// int power(int, int, int);
// int modInverse(int, int);

// worst question ever

void solve() {
    int n;
    cin >> n;
    // cout << n;


    int freq[100001] = {};

    int ele;
    for(int i = 0; i < n; i++) {
        cin >> ele;
        freq[ele]++;
    }

    int p2 = 0, p4 = 0;
    for(int i = 1; i <= 100000; i++) {
        p2 += freq[i] / 2;
        p4 += freq[i] / 4;
    }
    
    read(q);
    // cout << q;
    string type;
    int length;
    while(q--) {
        cin >> type;
        cin >> length;
        p2 -= freq[length] / 2;
        p4 -= freq[length] / 4;

        freq[length] += (type == "+" ? 1 : -1);

        p2 += freq[length] / 2;
        p4 += freq[length] / 4;

        // one square == p2 value of 2
        if(p4 && p2 >= 4) {
            cout << "YES\n";
        }
        else 
            cout << "NO\n";
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

	// for fast i/o
    fastIO

    // begin reading test cases
	solve();

    return 0;
}
