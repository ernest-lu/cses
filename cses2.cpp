#include<bits/stdc++.h>
using namespace std;

//var 
int n,a,N;
bool h[200001];

int main(){
	cin >> n; N=n;
	while(N--){
		cin >> a;
		h[a] = 1;
	}
	for(int i = 1; i<=n; i++){
		if(!h[i]){
			cout << i << endl;
			break;
		}
	}
}