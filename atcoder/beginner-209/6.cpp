//Author : Vivek Dubey
#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

ll lessThanK(vector<ll> &v, long long k)
{
    ll ans = 0;
    // all possible subsets
    for (int i = 1; i < (1 << (int)v.size()); i++)
    {
        ll prod = -1;
        cerr << i << endl;
        for (int j = 0; j < (int)v.size(); j++)
        {
            if (((1 << j) & i)) {
                if (prod == -1) prod = v[j];
                if(i == 4) {
                    cerr << j << " ";
                }
                cerr << v[j] << " ";
                prod = (prod * v[j]) / __gcd(v[j], prod);
            }
        }
        ans += (k / prod) * (__builtin_popcount(i) % 2 ? 1 : -1);
        cerr << endl;
    }

    return ans;

}

void solve() {
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll low = v[0], high = 1e9, ans = 0;

    // k < 1e15
    
    // num -> xth no
    // x < k, increase num
    // x > k, decrease num
    while (low <= high) {
        ll mid = (low + high) / 2;
        int curr = lessThanK(v, mid);

        if(curr == k) {
            ans = mid;
            break;
        }

        if (curr < k) {    
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
}

int32_t main() {
#ifdef CODINGINVEINS
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

    // test cases
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef CODINGINVEINS
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}