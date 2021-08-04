//Author : Vivek Dubey
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
using namespace __gnu_pbds; 
using namespace std; 

// Declaring ordered_set
typedef tree<int, null_type, less<int>, rb_tree_tag, 
            tree_order_statistics_node_update> 
    ordered_set;

const long long mod = 1e9 + 7;

const int N = 4e5 + 10;

int factorial[N];
int n;

int power(int base, int expo) {
    int res = 1;

    while(expo) {
        if(expo & 1) {
            res = (1LL * res * base) % mod;
            res %= mod;
        }

        base = (1LL * base * base) % mod;
        expo /= 2;

    }

    return res;
}

int modInverse(int n) {
    return power(n, mod - 2);
}

int combi(int n, int r) {
	if(r < 0) {
		return 0;
	}

    int num = factorial[n];
    int dem = (1LL * factorial[r] * factorial[n - r]) % mod;

    int ans = (1LL * num * modInverse(dem)) % mod;

    return ans;
}

void solve() {
    cin >> n;
    ordered_set s;

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int e, age;

        cin >> age >> e;
        s.insert(age);

        int small = s.order_of_key(age);

        if(i == 0) {
            cout << "0\n";
            continue;
        }

        swap(small, e);
        int curr = combi(small + e - 1, e - 1);
        
        cout << curr << "\n";
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
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    factorial[0] = factorial[1] = 1;

    for(int i = 2; i < N; i++) {
        factorial[i] = (1LL * i * factorial[i - 1]) % mod;
    }
    // test cases
    int t = 1;
        // cin >> t;
        for(int i = 1; i <= t; i++) {
        // cout << "Case #"<< i << ": ";
        solve();
        }

    return 0;
}