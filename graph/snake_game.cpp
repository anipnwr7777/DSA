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
vector<int> level;


void precomputation()
{
    //no precomputation
}

void bfs(int node){

	queue<int> q;
	q.push(node);
	visited[node] = true;
	level[node] = 0;

	// use level as it was used in bipartite graph.

	while(!q.empty()){

		int curr = q.front();
		q.pop();

		for(auto child: adj[curr]){
			if(visited[child] == false){

				q.push(child);
				visited[child] = true;
				level[child] = level[curr] + 1;
			}
		}

	}
}

void makeadj(int m){

	map<int,int> snakes_ladders;


	// map the values of ladders and snakes u --> v.

    while(m--){

        int a,b;
        cin >> a >> b;
        snakes_ladders[a] = b;
    }

    for(int i=1 ; i<=100 ; i++){

    	for(int j=1 ; j<=6 ; j++){

    		// for all the values add u --> v for current vlaue + 6, because dice has 6 values.
    		
    		int u=i , v=i+j;

    		// if we end at a value and have a snake or ladder there, then update the final value
    		// after going through the snake or the ladder.

    		if(snakes_ladders.count(v) == 1){

    			v = snakes_ladders[v];
    		}

    		// now the final vlaue after throwing the die or anything shouldn't be outside 100
    		// i.e. you can't do a (99+6) to reach 105.
    		// only make an edge when value is less than equal to 100.

    		if(v<=100){
    			adj[u].push_back(v);
    		}
    	}
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    // n = 100

    // m --> no of snakes or ladders.

    adj.resize(n+1);
    visited.resize(n+1);
    level.resize(n+1);   // level is used to store the answer as the smallest distance to reach any node.

    makeadj(m);

    bfs(1);

    cout << level[100] << endl;


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