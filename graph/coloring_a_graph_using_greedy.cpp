#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775700
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap
vector<vector<int>> adj;
vector<string> colorcode = {"blue", "red" , "green", "violet", "purple", "pink", "silver", "magenta"};

void makeadj(int edges) {
	while (edges--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

void solve() {
	int nodes, edges;
	cin >> nodes >> edges;
	adj.resize(nodes + 1);
	makeadj(edges);

	map<int,int> color;
	int uniquecolorsused = 0;
	for(int i=1 ; i<=nodes ; i++){
		set<int> neighbourcolor;		// store the color of neighbours oh the given node
		for(auto x:adj[i]){
			if(color[x])
				neighbourcolor.insert(color[x]);
		}
		int thiscolor = -1, num = 1;
		for(auto it=neighbourcolor.begin() ; it!=neighbourcolor.end() ; it++){
			if(num == *it){		// if color is already occupied then go to the next node and see it's color 
				num++;
				continue;
			}
			else		// color is found that is not taken
				break;
		}
		color[i] = num;		// take the next number(node) and set it as the color of the given node
		uniquecolorsused++;
	}

	// display the colors 
	cout << "minimum colors used here are: " << uniquecolorsused << endl;
	for(auto x:color)
		cout << "color of " << x.first << " node is : " << colorcode[x.second] << endl;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}