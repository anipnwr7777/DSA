#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
#define int long long
#define largest 9223372036854775700
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap

void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename t>
void __print(vector<t> v)
{
    cerr << endl;
    for (t x : v) {__print(x); cerr << " ";}
    cerr << endl;
}

template<typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}

template<typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print()
{
    cerr << "]\n";
}
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

//----------------------------------------------------------------------------------------------

vector<vector<int>> adj;
vector<bool> visited;
int n, m;

void precomputation()
{
    //no precomputation
}

void makeadj(int m) {
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
}

void dfs(int node, vector<vector<int>> adj) {
    visited[node] = 1;
    for (auto child : adj[node]) {
        if (visited[child] == 0) {
            dfs(child, adj);
        }
    }
}

bool check() {
    dfs(1, adj);
    if (find(visited.begin() + 1, visited.end(), false) != visited.end()) {
        // +1 is done because first index contains false, because our index starts from 1 and index 0
        // contains false which is of no use to us but hinders in the logic, so just ignore it and start from 
        // visited.begin() + 1
        return false;
    }
    // reverse the adj list
    vector<vector<int>> adjnew(n + 1);
    visited.clear();
    visited.resize(n + 1, 0);
    for (int i = 1 ; i <= n ; i++) {
        for (auto child : adj[i]) {
            adjnew[child].push_back(i);
        }
    }
    // check again
    dfs(1, adjnew);
    if (find(visited.begin() + 1, visited.end(), false) != visited.end()) {
        return false;
    }
    // finally if all of them are passing then return true.
    return true;
}

void solve()
{
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1);

    makeadj(m);
    cout << (check() ? "strongly connected" : "not strongly connected") << endl;
}

//------------------------------------------------------------------------------------------------

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    precomputation();

    solve();

    return 0;
}