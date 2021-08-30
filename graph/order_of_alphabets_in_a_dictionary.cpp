#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775700
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap
set<char> nodes;
map<char,vector<char>> adj;
vector<pair<char, char>> edges;
int timer = 0;
map<char, int> outtime;
map<char,bool> visited;
vector<pair<int,char>> topo;

void dfs(char node){
	visited[node] = 1;

    for(auto child: adj[node]){
        if(visited[child] == 0){
            dfs(child);
        }
    }
    outtime[node] = timer++;

    topo.push_back({outtime[node], node});  // just push the outtime with the node as pair
}

void makeadj(){
	for(int i=0 ; i<edges.size() ; i++){
		adj[edges[i].first].push_back(edges[i].second);
	}
}

void solve() {
	vector<vector<string>> words;
	int noofwords;
	cin >> noofwords;
	words.resize(noofwords);
	for (int i = 0 ; i < noofwords ; i++) {
		string s;
		cin >> s;
		words[i].push_back(s);
	}

	for (int i = 0 ; i < noofwords ; i++) {
		string word1 = words[i][0];
		for (int j = 1 ; j < word1.size() ; j++) {
			char a = word1[j-1];
			char b = word1[j];
			if(a != b){
				edges.push_back({a,b});
				nodes.insert(a);
				nodes.insert(b);
			}
		}
	}

	int noofNodes = nodes.size();
	int noofEdges = edges.size();

	// cout << noofEdges << " " << noofNodes << endl;
	makeadj();

	vector<char> alpha(noofNodes + 1);
	int index = 1;
	for(auto it=nodes.begin() ; it!=nodes.end() ; it++){
		alpha[index] = (*it);
		index++;
	}

	for(int i=1 ; i<=noofNodes ; i++){
		if(!visited[alpha[i]]){
			dfs(alpha[i]);
		}
	}

	for(auto it = topo.rend() ; it!=topo.rbegin() ; it--){
		cout << it->second << " ";
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}