#include<bits/stdc++.h>
using namespace std;

//var 
long long n;

int main(){
	cin >> n;
	while(n!=1){
		cout << n << " ";
		if(n%2){n*=3; n++;}
		else n = n/2;
	}cout << 1 << endl;
}