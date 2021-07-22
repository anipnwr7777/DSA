#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int src, des;
};

class Graph {
public:
	vector<vector<int>> adj;
	vector<bool> visited;
	Graph(vector<Edge> edges, int n) {
		adj.resize(n + 1);
		visited.resize(n + 1, 0);
		for (auto edge : edges) {
			adj[edge.src].push_back(edge.des);
		}
	}
	void print_adj(int n) {
		for (int i = 1 ; i <= 4 ; i++) {
			for (auto child : adj[i])
				cout << child << " ";
			cout << endl;
		}
	}
	void dfs(int node){
		visited[node] = true;
		cout << node << "-->" ;
		for(auto child: adj[node]){
			if(!visited[child])
				dfs(child);
		}
	}
};

int main()
{
	vector<Edge> edges1 = {{1, 2}, {2, 3}, {3, 4}};
	Graph g1(edges1, 4);
	g1.print_adj(4);
	g1.dfs(1);
	cout << endl;

	vector<Edge> edges2 = {{1, 2}, {1, 3}, {1, 4}, {2, 3}};
	Graph g2(edges2, 4);
	g2.print_adj(4);
	g2.dfs(1);
	cout << endl;

	return 0;
}