#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775700
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap

vector<vector<int>> adj;
vector<int> dist;
vector<bool> visited;

void dijkstra(int nodes) {
    int n = nodes;
    while (n--) {
        int mn = largest, curr;
        for (int i = 1 ; i <= nodes ; i++) {
            if (dist[i] < mn && visited[i] == 0) {
                mn = dist[i];
                curr = i;
            }
        }
        visited[curr] = true;
        for (int i = 1 ; i <= nodes ; i++) {
            if (!visited[i] && adj[curr][i] != 0 && dist[i] > (dist[curr] + adj[curr][i])) {
                dist[i] = dist[curr] + adj[curr][i];
            }
        }
    }
    for (int i = 1 ; i <= nodes ; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

void solve() {
    int nodes, edges, src;
    cin >> nodes >> edges >> src;
    adj.resize(nodes + 1);
    visited.resize(nodes + 1);
    dist.resize(nodes + 1, largest);
    dist[src] = 0;
    for (int i = 1 ; i <= nodes ; i++)
        adj[i].resize(nodes + 1);

    for (int i = 0 ; i < edges ; i++) {
        int a, b, wt;
        cin >> a >> b >> wt;
        adj[a][b] = wt;
    }

    dijkstra(nodes);
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}