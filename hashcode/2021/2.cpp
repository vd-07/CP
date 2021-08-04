/*
    * @authr AVINISH KUMAR
    * @college BIT MESRA
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define MOD 1000000007
#define maxn 100000000000017
#define endl "\n"
#define mk make_pair
#define pll pair<ll, ll>
#define vll vector<ll>
#define vld vector<ld>
#define vpll vector<ppl>
#define ff first
#define ss second
#define pb push_back

typedef long long ll;
typedef long double ld;

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

#define o(...)                          \
    if (local == 'L')                   \
    {                                   \
        __f(#__VA_ARGS__, __VA_ARGS__); \
        cout << endl;                   \
    }

#define Ns 1000007

char local = 'O';

////////////////#####################INPUT###############///////////////////////

template <typename T>
void read(T &p)
{
    cin >> p;
}

template <typename T, typename T1>
void read(pair<T, T1> &p)
{
    read(p.ff);
    read(p.ss);
}

template <typename T>
void read(T arr[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        read(arr[i]);
    }
}

template <typename T>
void read(vector<T> &arr)
{
    for (ll i = 0; i < arr.size(); i++)
    {
        read(arr[i]);
    }
}

////////////////#####################OUPUT###############///////////////////////

template <typename T>
void out(T &n)
{
    cout << n;
}

template <typename T, typename T1>
void out(pair<T, T1> &p)
{
    cout << "(";
    out(p.ff);
    cout << ",";
    out(p.ss);
    cout << ")";
}

template <typename T>
void out(T arr[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        out(arr[i]);
        cout << " ";
    }
}

template <typename T>
void out(vector<T> &arr)
{

    cout << "[ ";
    for (ll i = 0; i < arr.size(); i++)
    {
        out(arr[i]);
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << " ]";
}

template <typename T>
void out(set<T> &arr)
{
    for (auto i : arr)
    {
        out(i);
        cout << " ";
    }
}

template <typename T>
void out(multiset<T> &arr)
{
    for (auto i : arr)
    {
        out(i);
        cout << " ";
    }
}

template <typename T, typename T1>
void out(map<T, T1> &m)
{
    for (auto i : m)
    {
        out(i.first);
        cout << " -> ";
        out(i.second);
        cout << ", ";
    }
}

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : ";
    out(arg1);
}

template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : ";
    out(arg1);
    cout << " | ";
    __f(comma + 1, args...);
}

////////////////////////////////////END TEMPLATE//////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void cal()
{
}

int randomfunc(int j)
{
    return rand() % j;
}

void solve()
{
    srand(unsigned(time(0)));
    ll D, I, S, V, F;
    cin >> D >> I >> S >> V >> F;

    map<string, ll> street_name;
    vector<string> street_code;
    map<ll, vector<ll>> street;
    map<pair<ll, ll>, vector<ll>> intersection_pair;
    map<ll, vector<vector<ll>>> intersection_incoming_streets;

    for (ll i = 0; i < S; i++)
    {
        ll st, en, l;
        string name;
        cin >> st >> en >> name >> l;

        if (street_name.find(name) == street_name.end())
        {
            street_code.push_back(name);
            street_name[name] = street_code.size() - 1;
        }

        ll street_index = street_name[name];

        street[street_index] = {st, en, l};
        intersection_pair[{st, en}] = {street_index, l};
        intersection_incoming_streets[en].push_back({st, street_index, l});
    }

    map<pair<ll, ll>, ll> incoming_count;
    vector<vector<ll>> cars_path;

    map<ll, vector<ll>> ans;
    map<ll, ll> vis;

    for (ll i = 0; i < V; i++)
    {
        ll path_length;
        cin >> path_length;

        vector<ll> path;

        for (ll j = 0; j < path_length; j++)
        {
            string name;
            cin >> name;

            ll street_index = street_name[name];
            incoming_count[{street[street_index][1], street_index}]++;

            if (vis[street_index] != 1)
            {
                ans[street[street_index][1]].push_back(street_index);
                vis[street_index] = 1;
            }
            path.push_back(street_index);
        }
        cars_path.push_back(path);
    }

    cout << ans.size() << endl;
    for (auto &i : ans)
    {

        cout << i.first << endl;
        cout << i.second.size() << endl;

        ll max_time = 2;
        ll max_count = 0;

        for (auto &j : i.second)
        {
            // o(j)
            ll street_index = j;
            ll inc_count = incoming_count[{i.first, street_index}];
            max_count = max(inc_count, max_count);
        }

        max_count = max(max_time, max_count);

        vector<pair<pair<ll, ll>, string>> result;

        for (auto &j : i.second)
        {
            // o(j)
            ll street_index = j;
            string name = street_code[street_index];
            
            ll inc_count = incoming_count[{i.first, street_index}];

            ll t = (inc_count / max_count) * max_time + 1;
            result.push_back({{(t * inc_count), t}, name});
        }

        sort(result.begin(), result.end());

        for(auto i:result) {
            cout<<i.second<<" "<< (i.first.second % 3) <<endl;
        }
    }
}

int main()
{
    
    time_t start, end;
    time(&start);
    freopen("e.txt", "r", stdin);
	freopen("o5.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t1;

    t1 = 1;

    ll k = 1;
    // cin >> t1;

    cal();

    while (t1--)
    {
        solve();
    }

#ifdef L
    time(&end);
    double time_taken = double(end - start);
    cout << endl
         << endl
         << endl
         << "Time taken by program is : " << fixed
         << time_taken << setprecision(6);
    cout << " sec " << endl;
#endif
}