#include<bits/stdc++.h>
using namespace std;

int main(){
	map<pair<int,int>,int> mpp;
	mpp[{1,2}] = 2;
	for(auto x:mpp){
		cout << x.first.first << endl;
	}
    return 0;
}