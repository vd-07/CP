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

int power(int, int, int);
int modInverse(int, int);


void solve() {
    read4(n, m, sx, sy);

    int currx = 1, curry = sy;
    //curr column
    cout << sx << " " << sy << "\n";
    while(currx <= n) {
        if(currx != sx)
        cout << currx << " " << curry << "\n";
        currx++;
    }

    //after
    // currx--;
    for(curry = sy + 1; curry <= m; curry++) {
        currx = (currx == 0 ? 1 : n);
        if(currx == n) {
            while(currx >= 1) {
                cout << currx << " " << curry << "\n";
                currx--;
            }
        }
        else {
            while(currx <= n) {
                cout << currx << " " << curry << "\n";
                currx++;
            }
        }
    }

    //before
    // currx = (currx == 0 ? 1 : n);
    for(curry = sy - 1; curry >= 1; curry--) {
        currx = (currx == 0 ? 1 : n);
        if(currx == n) {
            while(currx >= 1) {
                cout << currx << " " << curry << "\n";
                currx--;
            }
        }
        else {
            while(currx <= n) {
                cout << currx << " " << curry << "\n";
                currx++;
            }
        }
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