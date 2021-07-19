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
vector<vector<bool>> is_connected;  // connectivity matrix.

void precomputation()
{
    //no precomputation
}

void makeadj(int m){

    // this is for directed graph.

    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
}

void dfs(int node, int root_node){

    visited[node] = 1;

    for(auto child: adj[node]){
        if(visited[child] == 0){

            is_connected[root_node][child] = true; // mark it as reachable.
            dfs(child, root_node);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    visited.resize(n+1);
    is_connected.resize(n+1);

    for(int i=0 ; i<=n ; i++){

        // make it a matrix by resizing
        is_connected[i].resize(n+1);

    }

    makeadj(m);

    for(int i=1 ; i<=n ; i++){

        // cleat the visited vector for each time and then resize and reinitialize it.
        visited.clear();
        visited.resize(n+1, false);

        dfs(i, i);
        is_connected[i][i] = true;
    }

    for(int i=1; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cout << is_connected[i][j] << " ";
        }
        cout << endl;
    }
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