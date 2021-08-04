//Author : Vivek Dubey
#include <bits/stdc++.h>
using namespace std;
// #define int long long int
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

int n, m;
vector<vector<bool>> visited;
string paths;
vector<vector<char>> s;
string ans = "#";

void dfs(int x, int y) {
    if(x < 0 || y < 0 || x == n || y == n || s[x][y] == '#')
        return;
    // visited[x][y] = true;
    // paths[path_index++] = {x, y};
    paths.push_back(s[x][y]);
    //optimization
    if(ans != "#") {
        int id = paths.size();
        bool ok = true;
        for(int i = 0; i + 1 < paths.size(); i++) {
            if(paths[i] != ans[i]) {
                ok = false;
                break;
            }
        }
        if(ok && ans[id - 1] < paths.back()) {
            // d2(paths, ans)
            paths.pop_back();
            // visited[x][y] = false;
            return;
        }
    }
    //destination
    if(x == n - 1 && y == m - 1) {
        if(ans == "#")
            ans = paths;
        else if(ans > paths)
            ans = paths;
    }
    else {
        //dfs continued
        dfs(x, y + 1);
        dfs(x + 1, y);
    }
    paths.pop_back();
    // visited[x][y] = false;
}
void recur(int x, int y, string temp = "") {
    if(x < 0 || y < 0 || !visited[x][y])
        return;
    // d1(s[x][y])
    temp.push_back(s[x][y]);
    if(x == 0 && y == 0) {
        d1(ans)
        if(ans < temp || ans == "#")
            ans = temp;
        return;
    }
    recur(x, y - 1, temp);
    recur(x - 1, y, temp);
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

    test {
        cin >> n >> m;
        visited = vector<vector<bool>> (n, vector<bool> (m, false));
        paths.clear();
        s = vector<vector<char>> (n, vector<char> (m));
        ans = "#";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> s[i][j];
            }
        }
        // dfs(0, 0);
        // bool ispossible[n][m] = {};
        
        // cout << visited[3][3] << endl;
        // recur(n - 1, m - 1);
        // queue<vector<pair<int, int>>> q;
        // vector<pair<int, int>> path;
        // path.push_back({0, 0});
        // q.push(path);
        // while(!q.empty) {
        //     path = q.front();
        //     q.pop();
        //     int x = path.back().first, y = path.back().second;
        //     if(x == n - 1 && y == m - 1) {
        //         string temp;
        //         for(auto e:path) {
        //             temp.push_back(s[e.first][e.second]);
        //         }
        //         if(ans == "#")
        //             ans = temp;
        //         else if(ans > temp)
        //             ans = temp;
        //     }

        // }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }



    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
    return 0;
}