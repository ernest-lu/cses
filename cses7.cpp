#include<bits/stdc++.h>
using namespace std;

//var 
int n;
long long ans,sq;

int main(){
	cin >> n;
	for(int i = 1; i<=n; i++){
		sq = i*i;
		ans = sq*(sq-1)/2;
		if(ans>2)ans -= 2*(i-2) * (2*(i-4)+6);
		cout << ans << endl;
	}
}