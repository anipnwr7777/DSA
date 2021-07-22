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

vector<int> Rank;
vector<int> parent;

void precomputation()
{
    //no precomputation
}

struct Edge{
	int wt, src, des;
};

bool comp(Edge e1, Edge e2){
	if(e1.wt < e2.wt)
		return true;
	else
		return false;
}

void makeset(vector<int> universe) {
    for (int i = 0 ; i < universe.size(); i++) {
        parent[universe[i]] = universe[i];
    }
}
int find(int ele) {
    if (parent[ele] != ele) {
        // path compression (flattening of the tree)
        return parent[ele] = find(parent[ele]);
    }
    else
        return ele;
}
void Union(int s1, int s2) {
    int p1 = find(s1);
    int p2 = find(s2);
    // this is done to balance the tree after each union
    if (Rank[p1] > Rank[p2]) {
        parent[p2] = p1;
    }
    else if (Rank[p1] < Rank[p2]) {
        parent[p1] = p2;
    }
    else {
        parent[p2] = p1;
        Rank[p1]++;
    }
}

void solve()
{
	int n, m;
	cin >> n >> m;
    vector<int> universe;
    for(int i=1 ; i<=n ; i++)
    	universe.push_back(i);
    Rank.resize(n+1, 0);
    parent.resize(n+1);
	vector<Edge> edges(m);

    makeset(universe);
    
    for(int i=0 ; i<m ; i++){
    	cin >> edges[i].wt >> edges[i].src >> edges[i].des;
    }
    sort(edges.begin(), edges.end(), comp);

    int cnt = 0;
    cout << "s d wt" << endl;
    for(int i=0 ; i<m ; i++){
    	if(cnt == (n-1))
    		break;
    	int a = edges[i].src, b = edges[i].des;
    	if(find(a) != find(b)){
    		Union(a,b);
    		cout << a << " " << b << " " << edges[i].wt << endl;
    		cnt++;
    	}
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