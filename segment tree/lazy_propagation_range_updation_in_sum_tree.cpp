#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775700
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap

vector<int> segmenttree, lazy;

void buildtree(int index, int start, int end, vector<int> array) {
	if (start == end) {
		segmenttree[index] = array[start];
		return;
	}
	int mid = (start + end) / 2;
	buildtree(2 * index, start, mid, array);
	buildtree(2 * index + 1, mid + 1, end, array);
	segmenttree[index] = segmenttree[2 * index] + segmenttree[2 * index + 1];
}

int query(int index, int segstart, int segend, int qstart, int qend) {
	if (lazy[index] != 0) {
		int data = lazy[index];
		lazy[index] = 0;
		segmenttree[index] += data * (segend - segstart + 1);
		if (segstart != segend) {
			lazy[2 * index] += data;
			lazy[2 * index + 1] += data;
		}
	}
	if (qend < segstart || qstart > segend)
		return 0;
	if (qstart == segstart && qend == segend)
		return segmenttree[index];

	int mid = (segstart + segend) / 2;
	int l = query(2 * index, segstart, mid, qstart, min(qend, mid));
	int r = query(2 * index + 1, mid + 1, segend, max(qstart, mid + 1), qend);
	return l + r;
}

void update(int index, int segstart, int segend, int qstart, int qend, int val) {
	// update the changes that very done in previous updations but very not committed in either query or updation function (if any)
	if (lazy[index] != 0) {
		int data = lazy[index];
		lazy[index] = 0;
		segmenttree[index] += data * (segend - segstart + 1);
		if (segstart != segend) {
			lazy[2 * index] += data;
			lazy[2 * index + 1] += data;
		}
	}

	// no range exist
	if (qend < segstart || qstart > segend)
		return;

	// exact range found that needs to be updated, the index node updates itself with the value( in the segment tree) but doesnot updates the children at this
	// moment, rather updates their corresponding node in lazy tree to be updated in segment tree in the future. 
	if (qstart == segstart && qend == segend) {
		segmenttree[index] += val * (segend - segstart + 1);

		if (segstart != segend) {
			lazy[2 * index] += val;
			lazy[2 * index + 1] += val;
		}
		return;
	}

	int mid = (segstart + segend) / 2;
	update(2 * index, segstart, mid, qstart, min(qend, mid), val);
	update(2 * index + 1, mid + 1, segend, max(qstart, mid + 1), qend, val);

	// update itself from the left and right children 
	segmenttree[index] = segmenttree[2 * index] + segmenttree[2 * index + 1];
}

void solve() {
	int n;
	cin >> n;
	vector<int> array(n + 1);
	segmenttree.resize(4 * n + 1), lazy.resize(4 * n + 1);
	for (int i = 1 ; i <= n ; i++) {
		cin >> array[i];
	}
	buildtree(1, 1, n, array);
	cout << query(1, 1, n, 1, 5) << endl;
	int qstart, qend, val;	// an updation is being made
	cin >> qstart >> qend >> val;
	update(1, 1, n, qstart, qend, val);
	cout << query(1, 1, n, 1, 1) << endl;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}