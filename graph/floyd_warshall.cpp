#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 100
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap

vector<vector<int>> adj;

void floyd(int nodes, int edges) {
	for (int k = 1; k <= nodes ; k++)		// k has to be outside, because we are relaxing every (i,j) for each k
		for (int i = 1 ; i <= nodes ; i++)
			for (int j = 1 ; j <= nodes ; j++) {
				if (adj[i][k] == largest || adj[k][j] == largest)		// no path exists
					continue;
				else {
					adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
				}
			}
}

void solve() {
	int nodes, edges;
	cin >> nodes >> edges;
	adj.resize(nodes + 1);
	for (int i = 1 ; i <= nodes ; i++) {
		adj[i].resize(nodes + 1, largest);		// every node is at infinite distance at first
	}
	for (int i = 1 ; i <= nodes ; i++)
		for (int j = 1 ; j <= nodes ; j++) {
			if (i == j)
				adj[i][j] = 0;					// self edge
		}

	for (int i = 1 ; i <= edges ; i++) {
		int a, b, distance;
		cin >> a >> b >> distance;
		adj[a][b] = distance;
	}
	floyd(nodes, edges);
	for(int i=1 ; i<=nodes ; i++){
		for(int j=1; j<=nodes ; j++)
			cout << adj[i][j] << " ";
		cout << endl;
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}