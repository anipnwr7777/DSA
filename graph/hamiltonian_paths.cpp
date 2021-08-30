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
vector<int> path;

void makeadj(int edges) {
	while (edges--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

void printpath() {
	for (auto x : path) {
		cout << x << " ";
	}
	cout << endl;
}

void hamiltonian(int node, int n) {
	if (path.size() == n) {
		printpath();
		return;		// go back from here, backtrack
	}

	for (auto child : adj[node]) {
		if (!visited[child]) {
			visited[child] = 1;
			path.push_back(child);	// reach the node

			hamiltonian(child, n);	// go recursively inside

			visited[child] = 0;		// backtrack
			path.pop_back();
		}
	}
}

void solve() {
	int nodes, edges;
	cin >> nodes >> edges;
	adj.resize(nodes + 1);
	visited.resize(nodes + 1);
	makeadj(edges);
	visited[1] = 1;
	path.push_back(1);
	hamiltonian(1, nodes);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}