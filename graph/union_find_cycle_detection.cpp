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
    makeset(universe);

    while(m--){
    	int a, b;
    	cin >> a >> b;
    	int p1 = find(a);
    	int p2 = find(b);
    	if(p1 == p2){
    		cout << "yes cylce is there" << endl;
    		return;
    	}
    	else
    		Union(a, b);
    }
    cout << "No the cycle is not present" << endl;

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