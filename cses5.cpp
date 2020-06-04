#include<bits/stdc++.h>
using namespace std;

//var 
int n,b[1000001];

int main(){
	cin >> n;
	if(n==2 || n==3){
		cout << "NO SOLUTION" << endl;
	}
	else{
		for(int j = (n%2?n:n-1); j>0; j-=2)cout << j << " ";
		for(int j = (n%2?n-1:n); j!=0; j-=2)cout << j << " ";
	}cout << endl;
}