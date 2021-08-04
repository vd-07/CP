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

int n, m;

vector<int> a, b;

map<int, vector<int>> whatinit;

int mxans = INT_MAX;

bool check(int n1, int n2, int bitt) {
    return !((n1 & n2) & (1 << bitt));
}

int solve1(int p = 10, int ans = 0) {
    if(p == -1) {
        return ans;
    }
    // bool ok = true;

    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(auto e:whatinit[a[i]]) {
            if(check(a[i], e, p)) {
                // done.pb(e);
                ok = false;
                break;
            }
        }
        if(ok) {
            return solve1(p - 1, ans | (1 << p));
        }
        // for(int j = 0; j < m; j++) {
        //     // if zero
        //     if(check(a[i], b[j], p)) {
        //         continue;
        //     }
        //     else {
        //         return solve1(p - 1, ans | (1 << p));
        //     }
        // }
    }

    for(int i = 0; i < n; i++) {
        vector<int> done;
        for(auto e:whatinit[a[i]]) {
            if(check(a[i], e, p)) {
                done.pb(e);
            }
        }
        whatinit[a[i]] = done;
        // for(int j = 0; j < m; j++) {
        //     // if zero
        //     if(check(a[i], b[j], p)) {
        //         continue;
        //     }
        //     else {
        //         return solve1(p - 1, ans | (1 << p));
        //     }
        // }
    }
    // if(!ok)
    //     ans = ans | (1 << p);
    return solve1(p - 1, ans);
    
}

void solve() {
    cin >> n >> m; 
    a = vector<int> (n);
    b = vector<int> (m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    for(int i = 0; i < n; i++) {
        whatinit[a[i]] = b;
    }

    cout << solve1();
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

    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif

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