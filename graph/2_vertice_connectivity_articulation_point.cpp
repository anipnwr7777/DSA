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
vector<int> intime;
int timer = 0;

void precomputation()
{
    //no precomputation
}

void makeadj(int m) {
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int dfs(int node, int parent) {

    visited[node] = 1;
    intime[node] = timer++;
    int tm = intime[node];

    for (auto child : adj[node]) {
        // if child is not visited then do something
        if (visited[child] == 0) { 
            tm = min(tm, dfs(child, node));
        }
        // else if the child is visited and is not the parent of node then do something
        else if (child != parent) {
            tm = min(tm, intime[child]);
        }
    }
    if (tm >= intime[parent] && parent != 1) {
        /*
            u --> v, this is being considered.
            dfs(v): dfs is on v, if v doesnot satisy the property of articulation point then, u is an articulation point.

            we ignore 1-->x, where x is a random child of 1, because root node holds certain special property and has to be 
            evaluated separately. that is why we ignore any u-->v, where v says that u is an articulation point (u being 1).

            everything else is same as bridge edge, just the condition differs.
            concept used is also same i.e. arrival and departure time of a vertex in a graph.
        */
        cout << parent << endl;
    }
    return tm;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1, 0);
    intime.resize(n + 1);
    makeadj(m);

    // if outdegree of 1 is more than 1, then 1 is an articulation point.
    if (adj[1].size() > 1) {
        cout << 1 << endl;
    }
    for (int i = 1 ; i <= n ; i++)
        if (visited[i] == 0)
            dfs(i, -1);
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