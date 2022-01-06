#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775700
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap

vector<vector<int>> segmenttree;
vector<int> inputar;

void build(int index, int segstart, int segend) {
	if (segstart == segend) {
		segmenttree[index].push_back(inputar[segstart]);
		return;
	}
	int mid = (segstart + segend)/2;
	build(2*index, segstart, mid);
	build(2*index+1, mid+1, segend);

	int i=0, j=0;
	while(i<segmenttree[2*index].size() && j<segmenttree[2*index+1].size()){
		if(segmenttree[2*index][i] <= segmenttree[2*index+1][j]){
			segmenttree[index].push_back(segmenttree[2*index][i]);
			i++;
		}
		else{
			segmenttree[index].push_back(segmenttree[2*index+1][j]);
			j++;
		}
	}
	while(i<segmenttree[2*index].size()){
		segmenttree[index].push_back(segmenttree[2*index][i]);
		i++;
	}
	while(j<segmenttree[2*index+1].size()){
		segmenttree[index].push_back(segmenttree[2*index+1][j]);
		j++;
	}
}

/*
	query format --> l r k
	i.e. count all the elements from l to r that are less than k
*/ 
int query(int index, int segstart, int segend, int qstart, int qend, int k){
	if(segstart > qend || segend < qstart){
		return 0;
	}
	if(segend == qend && segstart == qstart){
		int res = upper_bound(segmenttree[index].begin(), segmenttree[index].end(), k-1) - segmenttree[index].begin();
		return res;
	}
	int mid = (segend + segstart)/2;
	int l = query(2*index, segstart, mid, qstart, min(mid,qend), k);
	int r = query(2*index+1, mid+1, segend, max(mid+1, qstart), qend, k);
	return l+r;	
}

void solve() {
	// resize the segment tree
	int n, q, l, r, k;
	cin >> n;
	inputar.resize(n+1);
	segmenttree.resize(4*n+1);
	for(int i=1 ; i<=n ; i++){
		cin >> inputar[i];
	}
	build(1, 1, n);
	cin >> q;
	while(q--){
		cin >> l >> r >> k;
		cout << query(1, 1, n, l, r, k) << endl;
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}