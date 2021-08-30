#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775700
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap
vector<int> t;

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		t[v] = a[tl];
	}
	else{
		int tm = (tl+tr)/2;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int sum(int v, int tl, int tr, int l, int r){
	if(l>r){
		return 0;
	}
	if(l == tl && r == tr){
		return t[v];
	}
	int tm = (tl+tr)/2;
	return sum(v*2, tl, tm, l, min(r,tm)) + sum(v*2+1, tm+1, tr, max(l,tm+1),r);

}

void update(int v, int tl, int tr, int pos, int new_val){
	if(tl == tr){
		t[v] = new_val;
	}
	else{
		int tm = (tl+tr)/2;
		if(pos <= tm){
			update(v*2, tl, tm, pos, new_val);
		}
		else{
			update(v*2+1, tm+1, tr, pos, new_val);
		}
		t[v] = t[v*2] + t[v*2+1];
	}
}

void solve(){
    int n;
    cin >> n;
    t.resize(n+1);
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}