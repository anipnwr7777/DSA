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
bool is_cycle_present = false;


void precomputation()
{
    //no precomputation
}

void bfs(int node, int parent){

	queue<pair<int,int>> q;
	q.push({node,parent});
	visited[node] = true;

	while(!q.empty()){

		int curr = q.front().first;
        int parent = q.front().second;
		q.pop();

		for(auto child: adj[curr]){
			if(visited[child] == false){

				q.push({child,curr});
				visited[child] = true;
			}
            else if(child != parent){

                is_cycle_present = true;
            }

            // same logic as that of dfs with only one difference 
            // in dfs cycle is formed by back edge, however here it is formed by cross edge.

            // bfs doesn't have a back edge, just imagine how bfs works, that edge would have been a 
            // tree edge if it would have been there in the past. why would have bfs left it there for a back edge
            // bfs would have pushed it in the queue there itself and made it a tree edge.
		}

	}
}

void makeadj(int m){

    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    visited.resize(n+1);

    makeadj(m);

    bfs(1, -1);
    cout << (is_cycle_present? "yes present" : "not present") << endl;

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