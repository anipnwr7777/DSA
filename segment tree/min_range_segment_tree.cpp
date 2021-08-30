#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775700
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap

/*
	---------# RANGE MINIMUM SEGMENT TREE #-------------
*/

vector<int> segmenttree;

// building a minimum segment tree that stores minimum in all ranges {O(n)}
void buildtree(int index, int start, int end, vector<int> array) {
	if (start == end) {
		segmenttree[index] = array[start];
		return;
	}
	int mid = (start + end) / 2;
	buildtree(2 * index, start, mid, array);
	buildtree(2 * index + 1, mid + 1, end, array);
	segmenttree[index] = min(segmenttree[2 * index], segmenttree[2 * index + 1]);
}

// O(log(n))
int query(int index, int segstart, int segend, int qstart, int qend) {
	/*
	 > index is the index of the node of the segment tree at which we are standing
	 > segstart is the starting index of the range that starts at that index of segment tree

	 > every node in a segment tree has 2 informations
		1. the index of that node in segment tree array
		2. the range [l,r] whose information is stored at that index of the segment tree
	*/

	// 1 --> the range doesn't exist in the given segement and lies completely outside
	if (qend < segstart || qstart > segend)
		return largest;

	// 2 --> the range of query directly coincides with the present segment
	if (qstart == segstart && qend == segend)
		return segmenttree[index];

	// 3 --> all other cases like partial overlap from right or left or completely inside
	int mid = (segstart + segend) / 2;
	int l = query(2 * index, segstart, mid, qstart, min(qend, mid));
	int r = query(2 * index + 1, mid + 1, segend, max(qstart, mid + 1), qend);
	return min(l, r);
}

// O(log(n))
void update(int index, int segstart, int segend, int queryindex, int val){
	if(segstart == segend){
		segmenttree[index] = val;
		return;
	}
	int mid = (segstart + segend)/2;

	if(queryindex <= mid)
		update(2*index, segstart, mid, queryindex, val);
	else
		update(2*index+1, mid+1, segend, queryindex, val);

	segmenttree[index] = min(segmenttree[2*index], segmenttree[2*index+1]);
}

void solve() {
	int n;
	cin >> n;
	vector<int> array(n + 1);
	segmenttree.resize(4 * n + 1);
	for (int i = 1 ; i <= n ; i++) {
		cin >> array[i];
	}
	buildtree(1, 1, n, array);
	cout << query(1, 1, n, 1, 5) << endl;
	int queryindex, val;	// an updation is being made
	cin >> queryindex >> val;
	update(1, 1, n, queryindex, val);
	cout << query(1, 1, n, 2, 2) << endl;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}