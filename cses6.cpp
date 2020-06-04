#include<bits/stdc++.h>
using namespace std;

//var 
long long t,x,y,sq;

int main(){
	cin >> t;
	while(t--){
		cin >> x >> y;
		sq = max(x,y) * max(x,y);
		if(sq%2){
			if(x<=y)cout << sq - x + 1 << endl;
			else if(y<x)cout << sq - x + 1 - (x-y) << endl;
		}
		else{
			if(x>=y)cout << sq - y + 1 << endl;
			else if(y>x)cout << sq - y + 1 - (y-x) << endl;
		}
	}
}