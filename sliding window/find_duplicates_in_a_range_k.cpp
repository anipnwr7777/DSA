#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define largest 9223372036854775700
#define mod 1000000007
#define endl "\n"
//priority_queue <int, vector<int>, greater<int>> minheap

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> array(n);
    for(int i=0 ; i<n ; i++){
    	cin >> array[i];
    }

    bool found = false;
    map<int,int> lookup;
    for(int i=0 ; i<n ; i++){
    	if(lookup[array[i]] > 0){
    		found = true;
    		break;
    	}
    	lookup[array[i]]++;
    	if(i>=k){
    		lookup[array[i-k]]--;
    	}
    }
    cout << (found ? "yes" : "no") << endl;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}