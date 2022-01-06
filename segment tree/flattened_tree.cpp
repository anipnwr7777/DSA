#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775700
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap

vector<vector<int>> adj;
vector<bool> visited;
vector<int> intime;
vector<int> outtime;
int timer = 0;

void makeadj(int m, int n){
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
}
  
void dfs(int node){
    visited[node] = 1;
    intime[node] = timer++;     // take your time and increment for next node.
    cout << "in node " << node << endl;

    for(auto child: adj[node]){
        if(visited[child] == 0){
            dfs(child);
        }
    }
    outtime[node] = timer++;
    cout << "out of node " << node << endl;
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
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}