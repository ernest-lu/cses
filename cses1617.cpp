#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL pow2[1000001], MOD = 1e9+7, n;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	pow2[0] = 1;
	for(int i = 1; i<=1000000; i++){
		pow2[i] = pow2[i-1];
		pow2[i] *= (LL)2;
		pow2[i] += MOD; pow2[i] %= MOD;
	}

	cin >> n;
	cout << pow2[n] << endl;

	cout.flush();
	return 0;
}