#include<bits/stdc++.h>
using namespace std;

//var 
long long t,a,mx=0;
int n;

int main(){
	cin >> n;
	while(n--){
		cin >> a; mx = max(mx,a);
		if(a<mx)t+=mx-a;
	}cout << t << endl;
}