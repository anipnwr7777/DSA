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
vector<int> outtime;
int timer = 0;
/*
    timer is golbal here because we want it to be updated each second and want it to be available globally

    if we would have passed it to function then stack would have saved the state and would have given the
    same time when we would have returned and asked for the departure time.

    we don't want the saved state of time for each funtion to be used, we want the updated one.

    in a crux you are telling each node to take it's time and update it for the next node to use it and
    further update it. (beacuse the upcoming node will definitely have much more time than this node)

    we can do it for undirected graph also but it doesnot makes sense to do it for undirected because we want 
    a particular path to be followed by dfs and doesn't want it to return different values everytime by 
    following a different path everytime.
*/

void precomputation()
{
    //no precomputation
}

void makeadj(int m, int n){
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
}
  
void dfs(int node){

    visited[node] = 1;

    // this is the time when a node is first arrived.
    intime[node] = timer++;     // take your time and increment for next node.
    cout << node << "-->";

    for(auto child: adj[node]){
        if(visited[child] == 0){
            dfs(child);
            
            // don't write departure time here, the current node is still not processed here
            // it will be processed when we are out of the for loop.
        }
    }

    // this is the time when the node is beign departured
    outtime[node] = timer++;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    visited.resize(n+1);
    intime.resize(n+1);
    outtime.resize(n+1);
    makeadj(m,n);

    for(int i=1 ; i<=n ; i++)
        if(visited[i] == 0)
            dfs(i);

    cout << endl;
    for(int i=1 ; i<=n ; i++){
        cout << intime[i] << " " << outtime[i] << endl;
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